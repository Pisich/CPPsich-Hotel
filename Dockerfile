FROM alpine:latest

WORKDIR /usr/src/CPPsichHotel

COPY . .
RUN apk add git g++ \
  && g++ -o CPPsich_Hotel main.cpp

CMD ["./CPPsich_Hotel"]
