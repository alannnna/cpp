FROM ubuntu:latest

RUN apt-get update

# Install bazel
RUN apt-get install -y pkg-config zip g++ zlib1g-dev unzip python curl
RUN curl -OL https://github.com/bazelbuild/bazel/releases/download/0.17.2/bazel-0.17.2-installer-linux-x86_64.sh
RUN chmod +x bazel-0.17.2-installer-linux-x86_64.sh && ./bazel-0.17.2-installer-linux-x86_64.sh

# Install and configure vim
RUN apt-get install -y vim
ADD .vimrc /root/.vimrc

# Install other tools
RUN apt-get install -y tmux

# Install cmake
RUN apt-get install -y cmake

WORKDIR /opt/cpp
