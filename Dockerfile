FROM alpine:latest

WORKDIR /usr/src/CPPsichHotel

RUN apk add git g++ \
  && git clone https://github.com/pisich/cppsich-hotel.git . \
  && g++ -o CPPsich_Hotel main.cpp

CMD ["./CPPsich_Hotel"]
