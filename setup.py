from setuptools import setup, Extension, find_packages


ext_modules = [
    Extension(
        "rbtn.pypiRBTN",
        sources=[
            "C/RBTN.c",
            "C/TNlib.c",
        ],
        extra_compile_args=[
            "/std:c11",
            "/O2",
        ],
    )
]


setup(
    name="rbtn",
    version="0.1.8",
    package_dir={"": "src"},
    packages=find_packages("src"),
    ext_modules=ext_modules,
)