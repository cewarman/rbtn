from pathlib import Path

from setuptools import setup, find_packages
from setuptools.dist import Distribution


class BinaryDistribution(Distribution):
    def has_ext_modules(self):
        return True

README = Path(__file__).parent / "src/rbtn/README.md"

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

    long_description=README.read_text(encoding="utf-8"),
    long_description_content_type="text/markdown",
)