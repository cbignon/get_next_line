# DISCLAIMER
We made everything we could to make this project  both portable and 
reliable. This means the docker container
is running on a Centos 8 with a Centos 8 libc. It is likely this libc is 
different from the one used by Deepthought. 

To use this project during an official 42 peer evaluation, please follow these 
guidelines:
- If this project reports an error, check for yourself with guacamole
- If this project says a function is valid, check by yourself by reading 
the code or using guacamole
- If this project issues a warning, try to understand why it occurred, 
and decide if this is a valid behavior, or if this is a mistake
- Some of the tests rely on our personal interpretation of the subject. It is
 likely we got some of them wrong, if we report an error, make sure it is
  an error, and cannot be anything else

# at42 libft Unit-tests
This repository contain unit tests for the libft project at 42.

<!-- markdown-toc start - Don't edit this section. Run M-x markdown-toc-refresh-toc -->
**Table of Contents**

- [DISCLAIMER](#disclaimer)
- [at42 libft Unit-tests](#at42-libft-unit-tests)
    - [Getting Started](#getting-started)
        - [Quick Start](#quick-start)
        - [Install a container engine](#install-a-container-engine)
        - [Launch the container](#launch-the-container)
    - [Usage](#usage)
    - [Contact / Support / Help](#contact--support--help)
    - [Howto](#howto)
        - [Build the container image yourself](#build-the-container-image-yourself)
        - [Install Docker on MacOS](#install-docker-on-macos)
            - [Short version](#short-version)
            - [Long version](#long-version)
    - [Acknowledgments](#acknowledgments)
    - [Contributors](#contributors)
    - [License](#license)

<!-- markdown-toc end -->

## Getting Started
### Quick Start
The following script should help install this project on MacOS and Linux.
```sh
bash <(curl -sSL at42-tests.gitlab.io)
```

If it fails, refer to the following sections.

### Install a container engine
You need to install an OCI container engine.

The most popular is [docker](https://www.docker.com/get-started).

Alternatives exists, for example [podman](https://podman.io/getting-started/installation) is a GNU/Linux docker-compatible command line tool (you can replace `docker` by `podman`).

### Launch the container
``` sh
docker run --cap-add=SYS_PTRACE --rm -it -v ~/.ssh:/home/at42-libft-test/.ssh neirpyc/libft-test:latest
```
`--cap-add=SYS_PTRACE` is needed for memory leaks detection.
`-v ~/.ssh:/home/at42-libft-test/.ssh` provides your ssh keys to the container so you can connect to the vogosphere.

To check the **42 norm** add `-v /path/to/.norminette:/home/at42-libft-test/.norminette` before the image identifier (`neirpyc/libft-test` here). Change `/path/to/.norminette` to the path where the norminette is installed on your system.

## Usage
Inside the container, clone the repository containing the libft you want to test in the `libft` directory:
``` sh
git clone <url> libft
```

Then launch the tests with this command:
``` sh
make test
```

You can get more information with
``` sh
make all
./test.bin --help
```

## Contact / Support / Help
Contact us by mail at <incoming+at42-tests-libft-22575926-issue-@incoming.gitlab.com>.

You can also [create an new issue](https://gitlab.com/at42-tests/libft/-/issues/new?issue%5Bassignee_id%5D=&issue%5Bmilestone_id%5D=) on our gitlab project.

## Howto
### Build the container image yourself
If you prefer building the container image yourself first clone this repo and go inside:
``` sh
git clone https://gitlab.com/neirpyc/at42-libft-unit-tests
cd at42-libft-unit-tests
```

Build the image with this command:
``` sh
docker build .
```
Note the long base64 string at the end of the output, it's the id of your image.

Then to run it (by replacing <id> by the id of your image):
``` sh
docker run --cap-add=SYS_PTRACE --rm -it -v ~/.ssh:/home/at42-libft-test/.ssh <id>
```
See the section [Launch the container](#launch-the-container) for explanation of some options used here.

### Install Docker on MacOS

#### Short version

``` sh
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)" && brew install docker docker-machine && docker-machine create --driver virtualbox default && eval $(docker-machine env default)
```

If this returns an error related to VirtualBox, run (require root privilege):
```sh
brew cask install virtualbox
```


#### Long version

You should already have [Homebrew](https://brew.sh/) installed, if not:
``` sh
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"
```

Then you have to update the sources and install the Docker *formula* and its dependencies:
``` sh
brew update
brew install docker
brew install docker-machine
brew cask install virtualbox
```
You can skip the VirtualBox step if it is already installed.

You should now be able to create a Docker engine:
``` sh
docker-machine create --driver virtualbox default
```

Check if the docker engine is properly running:
``` sh
docker-machine ls
```

If the `STATE` is not running, launch the engine:
``` sh
docker-machine start default
```

Make sure that your Docker engine is running for the next steps. Last, we need to configure the environment variables for Docker. Run the following command to find out how:
``` sh
docker-machine env default
```

The command should usually be:
``` sh
eval $(docker-machine env default)
```

You should execute this each time you are launching Docker. If you are using it frequently, you can add this to your `~/.zshrc` :
``` sh
docker_running=$(docker-machine ls | grep default)
if [[ "$docker_running" == *"Running"* ]]
then
  eval "$(docker-machine env default)"
fi
```

Finally run a *hello work* to check if everything is working properly:
``` sh
docker run hello-world
```

Now you can [Launch the container](#launch-the-container) !

## Acknowledgments
Many thanks to [Snaipe](https://github.com/Snaipe) for these 2 useful projects:
- [Criterion](https://github.com/Snaipe/Criterion) - A cross-platform C and C++ unit testing framework for the 21st century. `MIT`
- [Mimick](https://github.com/Snaipe/Mimick) - A KISS, cross-platform C mocking library. `MIT`

This README is inpired by [Make a README](https://www.makeareadme.com/) by Danny Guo. `MIT`

## Contributors
The list contributors is in [CONTRIBUTORS.md](CONTRIBUTORS.md). Thanks you all!

Add yourself to it if you contributed to the project.

## License
This project uses [reuse-tool](https://reuse.software/) for handling license information.

[The .gitignore](.gitignore) and [the CONTRIBUTORS.md files](CONTRIBUTORS.md) are under the CC0-1.0 (see [the LICENSES/CC0-1.0.txt file](LICENSES/CC0-1.0.txt) for the license text.)

All others original source code is licensed under GPL-3.0-or-later (see [the LICENSES/GPL-3.0-or-later.txt file](LICENSES/GPL-3.0-or-later.txt) for the license text).

Look at the header in each file to find its license.
