FROM ubuntu:latest

COPY src/ .

RUN sed 's/main$/main universe/' -i /etc/apt/sources.list \
    && apt-get update \
    && chmod +x main.cpp \
    && apt-get install -y g++ \
    && g++ -o main main.cpp \
    && chmod +x main

CMD "./main"
