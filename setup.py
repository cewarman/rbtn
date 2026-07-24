from setuptools import setup, Extension, find_packages


module = Extension(
    "rbtn.pypiRBTN",
    sources=[
        "C/RBTN.c",
        "C/TNlib.c",
    ],
)


setup(
    name="rbtn",
    version="0.1.8",

    package_dir={"": "src"},
    packages=find_packages("src"),

    ext_modules=[
        module
    ],

    package_data={
        "rbtn": [
            "*.txt"
        ]
    },
)