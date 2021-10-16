FROM ubuntu:latest
WORKDIR /mount
RUN apt-get update \
    && DEBIAN_FRONTEND=noninteractive apt-get install -y \
        gcc \
        g++ \
        gcc-avr \
        avr-libc \
        cpputest \
        make \
        gdb-avr \
        pkg-config \
        avrdude \
        binutils-avr \
        minicom \
    && rm -rf /var/lib/apt/lists/*  
COPY avrduderc /root/.avrduderc
COPY minirc.dfl /etc/minicom/minirc.dfl
CMD ["make"]
