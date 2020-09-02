FROM 066650776666.dkr.ecr.eu-central-1.amazonaws.com/cosmo/eks-base:latest

#invalidate the cache when the head of the repo changes
ADD https://api.github.com/repos/cosunae/cloudruption/git/refs/heads/master version.json
RUN git clone https://github.com/cosunae/cloudruption.git 
RUN export eccodes_DIR=/usr/share/eccodes/lib/cmake/eccodes/ && \
    export FC=`which gortran-8` && export CXX=`which g++-8` && \
    cd /home/cloudruption/ProducerConsumer && pip3 install -v .

 
RUN mkdir /home/cloudruption/config    
RUN mkdir /data

EXPOSE 3000
ADD entrypoint.py /home/cloudruption/ProducerConsumer/aws/entrypoint.py

ENTRYPOINT ["/home/cloudruption/aws/producer_dash/entrypoint.py"]
#ENTRYPOINT ["/bin/bash"]
