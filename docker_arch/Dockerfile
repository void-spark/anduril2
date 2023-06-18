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

CMD [ "/bin/bash" ]
