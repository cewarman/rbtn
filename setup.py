from setuptools import setup, find_packages
from setuptools.dist import Distribution


class BinaryDistribution(Distribution):
    def has_ext_modules(self):
        return True


setup(
    distclass=BinaryDistribution,

    package_dir={"": "src"},
    packages=find_packages("src"),

    package_data={
        "rbtn": [
            "*.dll",
            "*.so",
            "*.dylib",
            "*.txt",
        ],
    },

    include_package_data=True,
)