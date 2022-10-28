# Anything that may be used for building, but is also needed in the final image
FROM ubuntu:latest AS base
RUN apt-get update -qq \
&& DEBIAN_FRONTEND=noninteractive apt-get install --no-install-recommends -y -q \
    avr-libc \
    avrdude \
    avrdude-doc \
    binutils-avr \
    bison \
    byacc \
    curl \
    flex \
    gcc \
    gcc-avr \
    libc6-dev \    
    libusb-dev \
    make \
    perl \
    python-is-python3 \
    unzip \
    less \
&& rm -rf /var/lib/apt/lists/*
RUN curl http://packs.download.atmel.com/Atmel.ATtiny_DFP.2.0.368.atpack > Atmel.ATtiny_DFP.2.0.368.atpack \
&& mkdir /opt/dfp \
&& unzip -o Atmel.ATtiny_DFP.2.0.368.atpack -d /opt/dfp \
&& chmod -R 777 /opt/dfp \
&& rm Atmel.ATtiny_DFP.2.0.368.atpack
ENV ATTINY_DFP="/opt/dfp"

CMD [ "/bin/bash" ]
