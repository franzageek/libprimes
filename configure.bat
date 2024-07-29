@echo off

::  *** LIBPRIMES 1.0.1 INSTALLER ***
::  *** developed by <franzageek> ***
::  
:: /*************************************************
::  *  libprimes is a free & open-source project    *
::  *  developed & maintained by <franzageek>.      *
::  *  You can discover it at the following link:   *
::  *  [https://github.com/franzageek/libprimes]    *
::  *                                               *
::  *  The code is licensed to you under the        *
::  *  MIT License (https://mit-license.org/).      *
::  *************************************************/

:: Build subdirectory {$CURRENT_DIR/$BUILD_DIR}
set BUILD_DIR="build"

:: Build configuration [Release||Debug]
set BUILD_CONFIG="Release"

:: Decide whether or not to run tests [true||false]
set RUN_TESTS="true"

echo //   libprimes v1.0.1   //
echo // made by ^<franzageek^> //

for %%a in (cmake, make, ctest) do (
    where %%a >nul 2>nul
    if %errorlevel% neq 0 (
        echo Error: %%a is not installed
        exit /b 1
    )
)

if not exist %BUILD_DIR% (
    mkdir %BUILD_DIR%
)

cd %BUILD_DIR%

if %RUN_TESTS% equ "true" (
    cmake -DCMAKE_BUILD_TYPE=%BUILD_CONFIG% ..
    make -j
    ctest -VV -j
    if %errorlevel% neq 0 (
        echo One or more tests failed. Aborting installation ^(build files will be kept^).
        exit /b 1
    )
    echo All tests passed, proceeding.
    cmake -DBUILD_TESTS=OFF -DCMAKE_BUILD_TYPE=%BUILD_CONFIG% .. >nul 2>&1
) else (
    cmake -DBUILD_TESTS=OFF -DCMAKE_BUILD_TYPE=%BUILD_CONFIG% ..
)

make install -j

exit /b
