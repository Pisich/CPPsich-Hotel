FROM alpine:latest

RUN apk add git g++\
  && git clone https://github.com/pisich/cppsich-hotel.git /source/ \
  && g++ -o CPPsich_Hotel /source/main.cpp

CMD ["./CPPsich_Hotel"]
