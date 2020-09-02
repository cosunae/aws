FROM 066650776666.dkr.ecr.eu-central-1.amazonaws.com/cosmo/eks-base:latest

WORKDIR /home/

#invalidate the cache when the head of the repo changes
ADD https://api.github.com/repos/cosunae/cloudruption/git/refs/heads/master version.json
RUN git clone https://github.com/cosunae/cloudruption.git 
RUN apt-get install -y gfortran-8
RUN cd  /home/cloudruption/ProducerConsumer  && export CXX=g++-8 && export CC=gcc-8 && export FC=gfortran-8 && \
    rm -rf build && mkdir build  && cd build &&  cmake  -DENABLE_FORTRAN=OFF -DENABLE_PRODUCER=ON -Deccodes_DIR=/usr/share/eccodes/lib/cmake/eccodes/ .. && \
    make -j3 && \
    export eccodes_DIR=/usr/share/eccodes/lib/cmake/eccodes/ && \
    cd /home/cloudruption/ProducerConsumer && pip3 install .

RUN pip3 install eccodes 
ENV LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/share/eccodes/lib/
RUN mkdir /home/cloudruption/config    
RUN mkdir /data
#ADD aws/entrypoint.py /home/cloudruption/ProducerConsumer/aws/entrypoint.py
#RUN chmod +x /home/cloudruption/ProducerConsumer/aws/entrypoint.py
RUN mkdir /root/.aws/
#ADD credentials /root/.aws/credentials

EXPOSE 3001
ENTRYPOINT ["/home/cloudruption/python/visualizeData.py","-v"]
#ENTRYPOINT ["/bin/bash"]
