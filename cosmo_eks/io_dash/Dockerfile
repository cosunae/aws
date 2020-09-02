FROM 066650776666.dkr.ecr.eu-central-1.amazonaws.com/cosmo/eks-base:latest

#invalidate the cache when the head of the repo changes
ADD https://api.github.com/repos/cosunae/cloudruption/git/refs/heads/master version.json
RUN git clone https://github.com/cosunae/cloudruption.git 
RUN pip3 install portion eccodes netcdf4
RUN cd  /home/cloudruption/ProducerConsumer  && export CXX=g++-8 && export CC=gcc-8 && export FC=`which gfortran-8` && \
    export eccodes_DIR=/usr/share/eccodes/lib/cmake/eccodes/ && \
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/share/eccodes/lib/ && \
    cd /home/cloudruption/ProducerConsumer && pip3 install -v .
 
RUN mkdir /home/cloudruption/config    
RUN mkdir /data
RUN mkdir /root/.aws/
ADD credentials /root/.aws/credentials

EXPOSE 3000
ENV LD_LIBRARY_PATH="/usr/share/eccodes/lib/:${LD_LIBRARY_PATH}"
ENTRYPOINT ["/home/cloudruption/python/toNetCDF_dash.py"]
