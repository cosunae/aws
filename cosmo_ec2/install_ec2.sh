sudo apt-get update
sudo apt-get -y install gcc-8 g++-8 gfortran-8 numactl

#install cuda
wget https://developer.download.nvidia.com/compute/cuda/repos/ubuntu1804/x86_64/cuda-ubuntu1804.pin
sudo mv cuda-ubuntu1804.pin /etc/apt/preferences.d/cuda-repository-pin-600
wget http://developer.download.nvidia.com/compute/cuda/10.2/Prod/local_installers/cuda-repo-ubuntu1804-10-2-local-10.2.89-440.33.01_1.0-1_amd64.deb
sudo dpkg -i cuda-repo-ubuntu1804-10-2-local-10.2.89-440.33.01_1.0-1_amd64.deb
sudo apt-key add /var/cuda-repo-10-2-local-10.2.89-440.33.01/7fa2af80.pub
sudo apt-get update
sudo apt-get -y install cuda

sudo apt-get -y install g++-8 gfortran-8 libssl-dev python3.8 libpython3.6-dev libpython3.8-dev librdkafka-dev libnetcdf-dev python3-distutils m4 unzip autoconf libtool environment-modules tcl libnuma-dev

  ## edit ssh config for github keys
cat  << EOF > ~/.ssh/config
Host github.com
User cosunae
Protocol 2
PubkeyAuthentication yes
PasswordAuthentication yes
StrictHostKeyChecking no 
IdentityFile ~/.ssh/id_github
EOF

sudo mkdir /data
sudo mkdir /software
sudo mount /dev/nvme0n1 /software
sudo mount /dev/nvme1n1 /data

cd /software/
git clone git@github.com:cosunae/aws.git
rm -rf openmpi-4.0.2*


#### INSTALLING openmpi
mkdir /software/opt/pgi/linux86-64-llvm/19.10/wrappers/

 cat > /software/opt/pgi/linux86-64-llvm/19.10/wrappers/pgf90  << EOF
#! /bin/bash
newargs=\`echo \$@ | sed s/-pthread//g -\`
/software/opt/pgi/linux86-64-llvm/19.10/bin/pgf90 \$newargs
exit
EOF

 cat > /software/opt/pgi/linux86-64-llvm/19.10/wrappers/pgfortran  << EOF
#! /bin/bash
newargs=\`echo \$@ | sed s/-pthread//g -\`
/software/opt/pgi/linux86-64-llvm/19.10/bin/pgfortran \$newargs
exit
EOF

chmod u+x /software/opt/pgi/linux86-64-llvm/19.10/wrappers/pgf90 /software/opt/pgi/linux86-64-llvm/19.10/wrappers/pgfortran
export PATH=/software/opt/pgi/linux86-64-llvm/19.10/wrappers/:/software/opt/pgi/linux86-64-llvm/19.10/bin:$PATH


wget https://download.open-mpi.org/release/open-mpi/v4.0/openmpi-4.0.4.tar.bz2
bunzip2 openmpi-4.0.4.tar.bz2
tar xvf openmpi-4.0.4.tar
cd openmpi-4.0.4

export FC=pgfortran
./configure --prefix=/software/openmpi --with-sge --disable-openib-udcm --with-cuda=/usr/local/cuda-10.2/

make install -j6


cd /software/spack-mch
git pull
cd /software
. spack/share/spack/setup-env.sh


spack dev-build --until=build cosmo@aws_5.07.mch1.0.p4%pgi cosmo_target=cpu ~cppdycore target=skylake_avx512 ~pollen ~serialize ~claw real_type=float ~eccodes  slave=aws
#spack install cosmo@aws_5.07.mch1.0.p4%pgi cosmo_target=cpu ~cppdycore target=skylake_avx512 ~pollen ~serialize ~claw real_type=double ~eccodes ~debug ~parallel slave=aws
#export GRIB_DEFINITION_PATH=/software/ubuntu/spack/install/aws/cosmo-grib-api-definitions/1.20.0.2/pgi/7rx3ibfvxg7e2sekwc7docjfoqp5gfwl/cosmoDefinitions/definitions/:/software/ubuntu/spack/install/aws/cosmo-grib-api/1.20.0.2/pgi/hezd2g2c3kgxf7uy5t6swegozefxcnxb/share/grib_api/definitions/
#export GRIB_SAMPLES_PATH=/software/ubuntu/spack/install/aws/cosmo-grib-api-definitions/1.20.0.2/pgi/7rx3ibfvxg7e2sekwc7docjfoqp5gfwl/cosmoDefinitions/samples/

export GRIB_DEFINITION_PATH=/software/ubuntu/spack/install/aws/cosmo-grib-api-definitions/1.20.0.2/pgi/nxpqveuu7lrh6vdcxrkslphx7a6hsf5x/cosmoDefinitions/definitions/:/software/ubuntu/spack/install/aws/cosmo-grib-api/1.20.0.2/pgi/vjlfzyfxjsqnyedclbslnzs7pqzcnrst/share/grib_api/definitions/
export GRIB_SAMPLES_PATH=/software/ubuntu/spack/install/aws/cosmo-grib-api-definitions/1.20.0.2/pgi/nxpqveuu7lrh6vdcxrkslphx7a6hsf5x/cosmoDefinitions/samples/
