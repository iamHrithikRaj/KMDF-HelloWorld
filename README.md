# KMDF Hello World Driver

This is a basic "Hello World" Kernel-Mode Driver Framework (KMDF) driver for Windows. It demonstrates the fundamental lifecycle of a WDF driver, including `DriverEntry` and `EvtDeviceAdd`.

## Project Structure

*   **Driver.c**: Contains the main entry point (`DriverEntry`) and the device addition callback (`KmdfHelloWorldEvtDeviceAdd`).
*   **KmdfHelloWorld.inf**: The installation information file required to install the driver.
*   **KmdfHelloWorld.vcxproj**: The Visual Studio project file, manually configured to build the driver and generate the catalog file.

## Prerequisites

*   Visual Studio 2022 (or compatible)
*   Windows Driver Kit (WDK) 10

## Building the Driver

1.  Open `KmdfHelloWorld.slnx` (or the project file directly) in Visual Studio.
2.  Select the **Debug** configuration and **x64** platform.
3.  Build the solution (**Build > Build Solution**).

The build process will:
1.  Compile the C code.
2.  Link the object files against the kernel libraries (`ntoskrnl.lib`, `WdfLdr.lib`, etc.).
3.  Generate the `.sys` driver file.
4.  Run `Inf2Cat` to verify the INF file and generate the `.cat` catalog file.

**Output Location:** `x64\Debug\`

## Installation (Testing)

To test this driver on a target machine (or VM):

1.  Enable test signing on the target machine:
    ```cmd
    bcdedit /set testsigning on
    ```
    (Reboot required)
2.  Copy the `x64\Debug` folder contents (`.sys`, `.inf`, `.cat`) to the target.
3.  Right-click `KmdfHelloWorld.inf` and select **Install**.
4.  Alternatively, use `devcon` to install:
    ```cmd
    devcon install KmdfHelloWorld.inf Root\KmdfHelloWorld
    ```

## Troubleshooting Build Issues

If the build fails with linker errors or missing files:
*   Ensure the WDK is correctly installed.
*   Check the `KmdfHelloWorld.vcxproj` file to ensure the library paths match your WDK version (currently set to `10.0.26100.0`).
