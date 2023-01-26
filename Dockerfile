FROM gcc:latest

ADD --keep-git-dir=true https://github.com/pisich/cppsich-hotel.git /source

RUN g++ -o CPPsich_Hotel main.cpp
CMD ["./CPPsich_Hotel"]
