FROM ubuntu:18.04

ARG cosmo_aws_secret_access_key
ARG cosmo_aws_access_key_id
ENV AWS_ACCESS_KEY_ID=${cosmo_aws_access_key_id}
ENV AWS_SECRET_ACCESS_KEY=${cosmo_aws_secret_access_key}

RUN apt-get update && apt-get install -y --no-install-recommends \
    libopenmpi-dev git libgcc-8-dev ssh  ca-certificates \
    make g++-8 gfortran-8 tar wget \
    python3-distutils libnetcdf-dev librdkafka-dev librdkafka1 librdkafka++1 \
    openssl libssl-dev curl unzip python3-pip python3-setuptools python3.7-dev \
    g++ llvm-9 llvm-9-runtime llvm-9-dev

RUN mkdir ~/temp && cd ~/temp && \
    wget https://github.com/Kitware/CMake/releases/download/v3.16.5/cmake-3.16.5.tar.gz && \
    tar -xzvf cmake-3.16.5.tar.gz && \
    cd cmake-3.16.5/ && export CC=gcc-8 && export  CXX=g++-8 && ./bootstrap && make -j4 && make install

RUN python3.7 -m pip install wheel
RUN python3.7 -m pip install numpy
RUN python3.7 -m pip install dash pandas squarify boto3 anytree confluent_kafka dash_treeview_antd sd_material_ui \
    dataclasses pyyaml portion eccodes netcdf4 
RUN export LLVM_CONFIG=`which llvm-config-9` && python3.7 -m pip install numba

WORKDIR /home/

RUN wget https://github.com/ecmwf/ecbuild/archive/3.1.0.tar.gz && \
    tar xvf 3.1.0.tar.gz
 
RUN wget https://github.com/ecmwf/eccodes/archive/2.12.0.tar.gz && \
    tar xvf 2.12.0.tar.gz && \
    cd eccodes-2.12.0 && mkdir build && cd build && \
    export CXX=g++-8 && export CC=gcc-8 && \
    /home/ecbuild-3.1.0/bin/ecbuild ../ -DENABLE_FORTRAN=OFF -DCMAKE_INSTALL_PREFIX=/usr/share/eccodes && \
    make -j4 install 

RUN curl "https://awscli.amazonaws.com/awscli-exe-linux-x86_64.zip" -o "awscliv2.zip" && \
    unzip awscliv2.zip && \
    ./aws/install

RUN mkdir -p ~/temp && cd ~/temp && git clone https://github.com/aws/aws-sdk-cpp && \
    export CXX=g++-8 && export CC=gcc-8 && cd aws-sdk-cpp && mkdir build && cd build \
    cmake ../ && make -j4 install
