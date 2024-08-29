FROM ubuntu

RUN apt-get update && apt-get install -y \
  g++ make valgrind vim libgtest-dev

COPY . /code

WORKDIR /code

CMD /bin/bash

