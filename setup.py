from setuptools import setup, Extension
from setuptools.dist import Distribution


class BinaryDistribution(Distribution):
    def has_ext_modules(self):
        return True


rbtn_extension = Extension(
    name="rbtn.pypiRBTN",
    sources=[
        "C/RBTN.c",
        "C/TNlib.c",
    ],
    extra_compile_args=[
        "-O3",
    ],
)


setup(
    distclass=BinaryDistribution,

    ext_modules=[
        rbtn_extension,
    ],

    package_dir={
        "": "src"
    },

    packages=[
        "rbtn"
    ],

    package_data={
        "rbtn": [
            "*.txt"
        ]
    },
)