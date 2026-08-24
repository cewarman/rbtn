from setuptools import setup, find_packages

setup(
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