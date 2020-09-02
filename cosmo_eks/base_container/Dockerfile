FROM ubuntu:18.04

ARG cosmo_aws_secret_access_key
ARG cosmo_aws_access_key_id
ENV aws_access_key_id={cosmo_aws_access_key_id}
ENV aws_secret_access_key={cosmo_aws_secret_access_key}

RUN echo "  AWS_SECRET_ACCESS_KEY : $aws_secret_access_key}  AWS_ACCESS_KEY_ID  ${aws_access_key_id}"
RUN apt-get update && apt-get install -y --no-install-recommends \
    libopenmpi-dev git libgcc-8-dev ssh  ca-certificates \
    make g++-8 gfortran-8 tar wget \
    python3.7-dev python3-distutils libnetcdf-dev librdkafka-dev librdkafka1 librdkafka++1 \
    openssl libssl-dev curl unzip python3-pip python3-setuptools python3-dev

RUN curl "https://awscli.amazonaws.com/awscli-exe-linux-x86_64.zip" -o "awscliv2.zip" && \
    unzip awscliv2.zip && \
    ./aws/install

RUN aws secretsmanager get-secret-value --secret-id arn:aws:secretsmanager:eu-central-1:066650776666:secret:cosmo_aws_access_key_id-t4v9FH \
   --region eu-central-1

#RUN mkdir ~/temp && cd ~/temp && \
#    wget https://github.com/Kitware/CMake/releases/download/v3.16.5/cmake-3.16.5.tar.gz && \
#    tar -xzvf cmake-3.16.5.tar.gz && \
#    cd cmake-3.16.5/ && export CC=gcc-8 && export  CXX=g++-8 && ./bootstrap && make -j4 && make install

#RUN pip3 install wheel
#RUN pip3 install dash pandas squarify boto3 anytree confluent_kafka dash_treeview_antd sd_material_ui \
#    dataclasses pyyaml portion eccodes netcdf4 numpy

##Numba fails with pip, so we perform the installation with conda
##RUN wget https://repo.anaconda.com/archive/Anaconda3-2020.02-Linux-x86_64.sh && \
##    bash Anaconda3-2020.02-Linux-x86_64.sh -b && /root/anaconda3/bin/conda init && \
##    /root/anaconda3/bin/conda install numba
#
#WORKDIR /home/
#
#RUN wget https://github.com/ecmwf/ecbuild/archive/3.1.0.tar.gz && \
#    tar xvf 3.1.0.tar.gz
# 
#RUN wget https://github.com/ecmwf/eccodes/archive/2.12.0.tar.gz && \
#    tar xvf 2.12.0.tar.gz && \
#    cd eccodes-2.12.0 && mkdir build && cd build && \
#    export CXX=g++-8 && export CC=gcc-8 && \
#    /home/ecbuild-3.1.0/bin/ecbuild ../ -DENABLE_FORTRAN=OFF -DCMAKE_INSTALL_PREFIX=/usr/share/eccodes && \
#    make -j4 install 
#RUN aws secretsmanager get-secret-value --secret-id arn:aws:secretsmanager:eu-central-1:066650776666:secret:cosmo_aws_access_key_id-t4v9FH
#RUN curl "https://awscli.amazonaws.com/awscli-exe-linux-x86_64.zip" -o "awscliv2.zip" && \
#    unzip awscliv2.zip && \
#    ./aws/install

