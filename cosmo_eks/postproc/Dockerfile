FROM 066650776666.dkr.ecr.eu-central-1.amazonaws.com/cosmo/eks-base:latest

WORKDIR /home/
 
RUN apt-get install -y openjdk-11-jre
RUN wget http://mirror.easyname.ch/apache/kafka/2.6.0/kafka_2.12-2.6.0.tgz && tar xvf kafka_2.12-2.6.0.tgz

#invalidate the cache when the head of the repo changes
ADD https://api.github.com/repos/cosunae/cloudruption/git/refs/heads/master version.json
RUN git clone https://github.com/cosunae/cloudruption.git 

RUN cd  /home/cloudruption/ProducerConsumer  && export CXX=g++-8 && export CC=gcc-8 && export FC=`which gfortran-8` && \
    export eccodes_DIR=/usr/share/eccodes/lib/cmake/eccodes/ && \
    cd /home/cloudruption/ProducerConsumer && python3.7 -m pip install -v .
 
RUN mkdir /home/cloudruption/config    
RUN mkdir /data
RUN mkdir /root/.aws/

EXPOSE 3000
ENV LD_LIBRARY_PATH="/usr/share/eccodes/lib/:${LD_LIBRARY_PATH}"
ENTRYPOINT ["/home/cloudruption/python/destaggering.py"]
