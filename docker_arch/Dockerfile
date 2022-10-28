# Anything that may be used for building, but is also needed in the final image
FROM archlinux:latest AS base

RUN pacman -Sy \
&& pacman -Su --noconfirm \
&& pacman -S --noconfirm \
    avr-binutils \
    avr-gcc \
    avr-gdb \
    avr-libc \
    avrdude \
    bison \
    byacc \
    curl \
    flex \
    gcc \
    glibc \
    libusb \
    make \
    perl \
    python \
    unzip

RUN curl http://packs.download.atmel.com/Atmel.ATtiny_DFP.2.0.368.atpack > Atmel.ATtiny_DFP.2.0.368.atpack \
&& mkdir /opt/dfp \
&& unzip -o Atmel.ATtiny_DFP.2.0.368.atpack -d /opt/dfp \
&& chmod -R 777 /opt/dfp \
&& rm Atmel.ATtiny_DFP.2.0.368.atpack

ENV ATTINY_DFP="/opt/dfp"

CMD [ "/bin/bash" ]
