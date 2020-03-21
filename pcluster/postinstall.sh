mkdir /scratch/build

cd /scratch/build

#apply patch
sudo patch /opt/amazon/openmpi/include/mpif-sizeof.h < patch.mpif-sizeof.h

sudo apt-get -y install gcc-8 g++-8 gfortran-8 numactl

#install cuda
wget https://developer.download.nvidia.com/compute/cuda/repos/ubuntu1804/x86_64/cuda-ubuntu1804.pin
sudo mv cuda-ubuntu1804.pin /etc/apt/preferences.d/cuda-repository-pin-600
wget http://developer.download.nvidia.com/compute/cuda/10.2/Prod/local_installers/cuda-repo-ubuntu1804-10-2-local-10.2.89-440.33.01_1.0-1_amd64.deb
sudo dpkg -i cuda-repo-ubuntu1804-10-2-local-10.2.89-440.33.01_1.0-1_amd64.deb
sudo apt-key add /var/cuda-repo-10-2-local-10.2.89-440.33.01/7fa2af80.pub
sudo apt-get update
sudo apt-get -y install cuda

# install pgi
mkdir -p /scratch/var/tmp
wget -q -nc --no-check-certificate -O /scratch/var/tmp/pgi-community-linux-x64-latest.tar.gz --referer https://www.pgroup.com/products/community.htm?utm_source=hpccm\&utm_medium=wgt\&utm_campaign=CE\&nvid=nv-int-14-39155 -P /scratch/var/tmp https://www.pgroup.com/support/downloader.php?file=pgi-community-linux-x64
mkdir -p /scratch/var/tmp/pgi
tar -x -f /scratch/var/tmp/pgi-community-linux-x64-latest.tar.gz -C /scratch/var/tmp/pgi -z
cd /scratch/var/tmp/pgi
sudo PGI_ACCEPT_EULA=accept PGI_INSTALL_DIR=/scratch/opt/pgi PGI_INSTALL_MPI=false PGI_INSTALL_NVIDIA=true PGI_MPI_GPU_SUPPORT=false PGI_SILENT=true ./install 
sudo rm -rf /scratch/var/tmp/pgi-community-linux-x64-latest.tar.gz /scratch/var/tmp/pgi

## edit ssh config for github keys
cat  << EOF > ~/.ssh/config
Host github.com
User cosunae
Protocol 2
PubkeyAuthentication yes
PasswordAuthentication yes
IdentityFile ~/.ssh/id_github
EOF


#creating env modules
mkdir -p /scratch/modules/pgi

cat << EOF > /scratch/modules/pgi/19.10
#%Module
proc ModulesHelp { } {
    puts stderr {

Description
===========
C, C++ and Fortran compilers from The Portland Group - PGI


More information
================
 - Homepage: http://www.pgroup.com/
    }
}

module-whatis {Description: C, C++ and Fortran compilers from The Portland Group - PGI}
module-whatis {Homepage: http://www.pgroup.com/}
module-whatis {URL: http://www.pgroup.com/}

set root /scratch/opt/pgi/

prepend-path    LD_LIBRARY_PATH         \$root/linux86-64-llvm/19.10/lib
prepend-path    LIBRARY_PATH            \$root/linux86-64-llvm/19.10/lib
prepend-path    MANPATH         \$root/linux86-64-llvm/19.10/man
prepend-path    PATH            \$root/linux86-64-llvm/19.10/bin
setenv  VERSIONPGI            "19.10"

setenv  PGI             "\$root"
# Built with EasyBuild version 4.0.0

EOF

mkdir -p /scratch/modules/gcc

cat << EOF > /scratch/modules/gcc/8.3.0
#%Module
proc ModulesHelp { } {
    puts stderr {

Description
===========
The GNU Compiler Collection includes front ends for C, C++, Objective-C, Fortran, Java, and Ada,
 as well as libraries for these languages (libstdc++, libgcj,...).


More information
================
 - Homepage: http://gcc.gnu.org/
    }
}

module-whatis {Description: The GNU Compiler Collection includes front ends for C, C++, Objective-C, Fortran, Java, and Ada,
 as well as libraries for these languages (libstdc++, libgcj,...).}
module-whatis {Homepage: http://gcc.gnu.org/}
module-whatis {URL: http://gcc.gnu.org/}

set root /usr/

setenv  ROOTGCC               "\$root"
setenv  VERSIONGCC            "8.3.0"

prepend-path    CPATH           \$root/include
prepend-path    LD_LIBRARY_PATH         \$root/lib
prepend-path    LD_LIBRARY_PATH         \$root/lib64
prepend-path    LD_LIBRARY_PATH         \$root/lib/gcc/x86_64-pc-linux-gnu/8.3.0
prepend-path    LIBRARY_PATH            \$root/lib
prepend-path    LIBRARY_PATH            \$root/lib64
prepend-path    MANPATH         \$root/share/man
prepend-path    PATH            \$root/bin
setenv  ROOTGCCCORE           "\$root"
setenv  VERSIONGCCCORE                "8.3.0"

EOF

cat << EOF > /scratch/modules/cuda/10.2
#%Module
proc ModulesHelp { } {
    puts stderr {

Description
===========
C, C++ and Fortran compilers from The Portland Group - PGI


More information
================
 - Homepage: http://www.pgroup.com/
    }
}

module-whatis {Description: C, C++ and Fortran compilers from The Portland Group - PGI}
module-whatis {Homepage: http://www.pgroup.com/}
module-whatis {URL: http://www.pgroup.com/}

set root /usr/local/cuda-10.2/

prepend-path    LD_LIBRARY_PATH         \$root/lib64
prepend-path    LIBRARY_PATH            \$root/lib64
prepend-path    PATH            \$root/bin
setenv  VERSIONCUDA            "10.2"

setenv  CUDA_HOME             "\$root"
setenv  CUDA_ROOT             "\$root"
EOF

ssh-keyscan github.com >> githubKey
echo `ssh-keygen -lf githubKey` > >> ~/.ssh/known_hosts

cd /scratch/
git clone git@github.com:cosunae/spack-mch.git
cd spack-mch
git checkout aws

./config.sh -i /scratch/ -m aws
. /scratch/spack/share/spack/setup-env.sh 
spack -vv install cosmo@aws_5.07.mch1.0.p4%pgi cosmo_target=cpu

