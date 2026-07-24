from setuptools import setup, Extension, find_packages
from pathlib import Path


ext_modules = [
    Extension(
        name="rbtn.pypiRBTN",
        sources=[
            "C/RBTN.c",
            "C/TNlib.c",
        ],
        extra_compile_args=[
            "-O3",
        ],
    )
]


setup(
    name="rbtn",
    version="0.1.8",

    package_dir={"": "src"},
    packages=find_packages("src"),

    ext_modules=ext_modules,

    package_data={
        "rbtn": [
            "*.txt",
        ]
    },
)