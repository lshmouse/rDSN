#!/bin/bash

scripts_path=`readlink -f $0`
scripts_dir=`dirname $scripts_path`/Linux

function usage()
{
    echo "usage: run.sh <command> [<args>]"
    echo
    echo "Command list:"
    echo "   help        print the help info"
    echo "   build       build the system"
    echo "   install     install the system"
    echo "   test        test the system, see build for help"
    echo "   start_zk    start the local single zookeeper server"
    echo "   stop_zk     stop the local single zookeeper server"
    echo "   clear_zk    stop the local single zookeeper server and clear the data"
    echo "   format      check the code format"
    echo "   publish     publish the program"
    echo "   publish_docker"
    echo "               publish the program docker image"
    echo "   republish   republish the program without changes to machinelist and config.ini files"
    echo "   republish_docker"
    echo "               republish the program docker image without changes to machinelist and config.ini files"
    echo "   deploy      deploy the program to remote machine"
    echo "   start       start program at remote machine"
    echo "   stop        stop program at remote machine"
    echo "   clean       clean deployed program at remote machine"
    echo "   k8s_deploy  deploy onto kubernetes cluster"
    echo "   k8s_undeploy"
    echo "               undeploy from kubernetes cluster"
    echo
    echo "Command 'run.sh <command> -h' will print help for subcommands."
}

#####################
## build
#####################
function usage_build()
{
    echo "Options for subcommand 'build':"
    echo "   -h|--help         print the help info"
    echo "   -t|--type         build type: debug|release, default is debug"
    echo "   -g|--git          git source of ext module: github|xiaomi, default is github"
    echo "   -c|--clear        clear the environment before building"
    echo "   -j|--jobs <num>"
    echo "                     the number of jobs to run simultaneously, default 8"
    echo "   -b|--boost_dir <dir>"
    echo "                     specify customized boost directory,"
    echo "                     if not set, then use the system boost"
    echo "   -w|--warning_all  open all warnings when build, default no"
    echo "   --enable_gcov     generate gcov code coverage report, default no"
    echo "   --build_plugins   build all plugins as well, default no"
    echo "   -v|--verbose      build in verbose mode, default no"
}
function run_build()
{
    BUILD_TYPE="debug"
    GIT_SOURCE="github"
    CLEAR=NO
    JOB_NUM=8
    BOOST_DIR=""
    WARNING_ALL=NO
    ENABLE_GCOV=NO
    RUN_VERBOSE=NO
    BUILD_PLUGINS=NO
    while [[ $# > 0 ]]; do
        key="$1"
        case $key in
            -h|--help)
                usage_build
                exit 0
                ;;
            -t|--type)
                BUILD_TYPE="$2"
                shift
                ;;
            -g|--git)
                GIT_SOURCE="$2"
                shift
                ;;
            -c|--clear)
                CLEAR=YES
                ;;
            -j|--jobs)
                JOB_NUM="$2"
                shift
                ;;
            -b|--boost_dir)
                BOOST_DIR="$2"
                shift
                ;;
            -w|--warning_all)
                WARNING_ALL=YES
                ;;
            --enable_gcov)
                ENABLE_GCOV=YES
                ;;
            --build_plugins)
                BUILD_PLUGINS=YES
                ;;
            -v|--verbose)
                RUN_VERBOSE=YES
                ;;            
            *)
                echo "ERROR: unknown option \"$key\""
                echo
                usage_build
                exit -1
                ;;
        esac
        shift
    done
    if [ "$BUILD_TYPE" != "debug" -a "$BUILD_TYPE" != "release" ]; then
        echo "ERROR: invalid build type \"$BUILD_TYPE\""
        echo
        usage_build
        exit -1
    fi
    if [ "$GIT_SOURCE" != "github" -a "$GIT_SOURCE" != "xiaomi" ]; then
        echo "ERROR: invalid git source \"$GIT_SOURCE\""
        echo
        usage_build
        exit -1
    fi    
    BUILD_TYPE="$BUILD_TYPE" GIT_SOURCE="$GIT_SOURCE" CLEAR="$CLEAR" JOB_NUM="$JOB_NUM" \
        BOOST_DIR="$BOOST_DIR" WARNING_ALL="$WARNING_ALL" ENABLE_GCOV="$ENABLE_GCOV" \
        RUN_VERBOSE="$RUN_VERBOSE" BUILD_PLUGINS="$BUILD_PLUGINS" $scripts_dir/build.sh
}

#####################
## test
#####################
function usage_test()
{
    echo "Options for subcommand 'build':"
    echo "   -h|--help         print the help info"
    echo "   --enable_gcov     generate gcov code coverage report, default no"
    echo "   -v|--verbose      build in verbose mode, default no"
    echo "   -m|--test_module  TODO: specify modules to test, split by ',',"
    echo "                     e.g., \"dsn.core.tests,dsn.tests\","
    echo "                     if not set, then run all tests"
}

function run_test()
{
    ENABLE_GCOV=NO
    RUN_VERBOSE=NO
    TEST_MODULE=""
    while [[ $# > 0 ]]; do
        key="$1"
        case $key in
            -h|--help)
                usage_test
                exit 0
                ;;
            --enable_gcov)
                ENABLE_GCOV=YES
                ;;
            -v|--verbose)
                RUN_VERBOSE=YES
                ;;
            -m|--test_module)
                TEST_MODULE="$2"
                shift
                ;;
            *)
                echo "ERROR: unknown option \"$key\""
                echo
                usage_test
                exit -1
                ;;
        esac
        shift
    done
    ENABLE_GCOV="$ENABLE_GCOV" RUN_VERBOSE="$RUN_VERBOSE" TEST_MODULE="$TEST_MODULE" $scripts_dir/test.sh
}

#####################
## install
#####################
function usage_install()
{
    echo "Options for subcommand 'install':"
    echo "   -h|--help         print the help info"
    echo "   -d|--install_dir <dir>"
    echo "                     specify the install directory,"
    echo "                     if not set, then default is './install'"
}
function run_install()
{
    INSTALL_DIR=$DSN_ROOT
    if [ ! -d $INSTALL_DIR ]
    then
        INSTALL_DIR=`pwd`/install
    fi

    while [[ $# > 0 ]]; do
        key="$1"
        case $key in
            -h|--help)
                usage_install
                exit 0
                ;;
            -d|--install_dir)
                INSTALL_DIR="$2"
                shift
                ;;
            *)
                echo "ERROR: unknown option \"$key\""
                echo
                usage_install
                exit -1
                ;;
        esac
        shift
    done
    INSTALL_DIR="$INSTALL_DIR" $scripts_dir/install.sh
}

#####################
## start_zk
#####################
function usage_start_zk()
{
    echo "Options for subcommand 'start_zk':"
    echo "   -h|--help         print the help info"
    echo "   -d|--install_dir <dir>"
    echo "                     zookeeper install directory,"
    echo "                     if not set, then default is './.zk_install'"
    echo "   -p|--port <port>  listen port of zookeeper, default is 12181"
    echo "   -g|--git          git source to download zookeeper: github|xiaomi, default is github"
}
function run_start_zk()
{
    INSTALL_DIR=`pwd`/.zk_install
    PORT=12181
    GIT_SOURCE="github"
    while [[ $# > 0 ]]; do
        key="$1"
        case $key in
            -h|--help)
                usage_start_zk
                exit 0
                ;;
            -d|--install_dir)
                INSTALL_DIR=$2
                shift
                ;;
            -p|--port)
                PORT=$2
                shift
                ;;
            -g|--git)
                GIT_SOURCE=$2
                shift
                ;;
            *)
                echo "ERROR: unknown option \"$key\""
                echo
                usage_start_zk
                exit -1
                ;;
        esac
        shift
    done
    INSTALL_DIR="$INSTALL_DIR" PORT="$PORT" GIT_SOURCE="$GIT_SOURCE" $scripts_dir/start_zk.sh
}

#####################
## stop_zk
#####################
function usage_stop_zk()
{
    echo "Options for subcommand 'stop_zk':"
    echo "   -h|--help         print the help info"
    echo "   -d|--install_dir <dir>"
    echo "                     zookeeper install directory,"
    echo "                     if not set, then default is './.zk_install'"
}
function run_stop_zk()
{
    INSTALL_DIR=`pwd`/.zk_install
    while [[ $# > 0 ]]; do
        key="$1"
        case $key in
            -h|--help)
                usage_stop_zk
                exit 0
                ;;
            -d|--install_dir)
                INSTALL_DIR=$2
                shift
                ;;
            *)
                echo "ERROR: unknown option \"$key\""
                echo
                usage_stop_zk
                exit -1
                ;;
        esac
        shift
    done
    INSTALL_DIR="$INSTALL_DIR" $scripts_dir/stop_zk.sh
}

#####################
## clear_zk
#####################
function usage_clear_zk()
{
    echo "Options for subcommand 'clear_zk':"
    echo "   -h|--help         print the help info"
    echo "   -d|--install_dir <dir>"
    echo "                     zookeeper install directory,"
    echo "                     if not set, then default is './.zk_install'"
}
function run_clear_zk()
{
    INSTALL_DIR=`pwd`/.zk_install
    while [[ $# > 0 ]]; do
        key="$1"
        case $key in
            -h|--help)
                usage_clear_zk
                exit 0
                ;;
            -d|--install_dir)
                INSTALL_DIR=$2
                shift
                ;;
            *)
                echo "ERROR: unknown option \"$key\""
                echo
                usage_clear__zk
                exit -1
                ;;
        esac
        shift
    done
    INSTALL_DIR="$INSTALL_DIR" $scripts_dir/clear_zk.sh
}

#####################
## format
#####################
function usage_format()
{
    echo "Options for subcommand 'format':"
    echo "   -h|--help         print the help info"
}
function run_format()
{
    while [[ $# > 0 ]]; do
        key="$1"
        case $key in
            -h|--help)
                usage_format
                exit 0
                ;;
            *)
                echo "ERROR: unknown option \"$key\""
                echo
                usage_format
                exit -1
                ;;
        esac
        shift
    done
    $scripts_dir/format.sh
}

####################################################################

if [ $# -eq 0 ]; then
    usage
    exit 0
fi
cmd=$1
case $cmd in
    help)
        usage ;;
    build)
        shift
        run_build $* ;;
    install)
        shift
        run_install $* ;;
    test)
        shift
        run_test $* ;;
    start_zk)
        shift
        run_start_zk $* ;;
    stop_zk)
        shift
        run_stop_zk $* ;;
    clear_zk)
        shift
        run_clear_zk $* ;;
    format)
        shift
        run_format $* ;;
    publish|publish_docker|republish|republish_docker)
        $scripts_dir/publish.sh $* ;;
    deploy|start|stop|clean)
        $scripts_dir/deploy.sh $* ;;
    k8s_deploy|k8s_undeploy)
        $scripts_dir/k8s_deploy.sh $* ;;
    *)
        echo "ERROR: unknown command $cmd"
        echo
        usage
        exit -1
esac

