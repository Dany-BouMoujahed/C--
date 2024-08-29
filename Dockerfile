FROM ubuntu

WORKDIR /home
RUN apt-get update
RUN apt-get install -y g++
Copy . .

RUN g++ test.cpp -o a.out
RUN g++ arrays.cpp -o b.out

ENTRYPOINT ./a.out && ./b.out
