from setuptools import setup
from setuptools.command.build_py import build_py
from setuptools.dist import Distribution
import subprocess
import os
import shutil
import platform
from pathlib import Path

class BinaryDistribution(Distribution):

    def has_ext_modules(self):
        return True


class BuildLibrary(build_py):

    def run(self):

        # 先正常 build python package
        build_py.run(self)

        root = Path(__file__).parent

        output = (
            Path(self.build_lib)
            / "rbtn"
        )


        system = platform.system()


        if system == "Linux":
            libname = "pypiRBTN.so"

        elif system == "Darwin":
            libname = "pypiRBTN.dylib"

        elif system == "Windows":
            libname = "pypiRBTN.dll"


        build_dir = "src/rbtn"

        os.makedirs(build_dir, exist_ok=True)


        if system == "Linux":

            subprocess.check_call([
                "gcc",
                "-shared",
                "-fPIC",
                "-Ofast",
                "C/RBTN.c",
                "C/TNlib.c",
                "-o",
                f"{str(output)}/{libname}"
            ])


        elif system == "Darwin":

            subprocess.check_call([
                "clang",
                "-shared",
                "-fPIC",
                "C/RBTN.c",
                "C/TNlib.c",
                "-o",
                f"{str(output)}/{libname}"
            ])


        elif system == "Windows":

            subprocess.check_call([
                "gcc",
                "-Ofast",
                "-shared",
                "C/RBTN.c",
                "C/TNlib.c",
                "-o",
                f"{str(output)}/{libname}"
            ])



setup(
    distclass=BinaryDistribution,

    cmdclass={
        "build_py": BuildLibrary
    }
)