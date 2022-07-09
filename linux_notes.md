Compile Examples in Linux
-------------------------
1. Can't find ewl_c9x.specs
File is located at:
NXP/S32DS_Power_v2.1/S32DS/build_tools/e200_ewl2/lib/ewl_c9x.specs

--sysroot  set at
Target Processor: `--sysroot="${VLE_EWL_DIR}"`  (was --sysroot="${eclipse_home}../S32DS/e200_ewl2")

2. lib_c99.prefix
File is located at:
/home/marco/NXP/S32DS_Power_v2.1/S32DS/build_tools/e200_ewl2/EWL_C/include/lib_c99.prefix
Example; `"${eclipse_home}../S32DS/e200_ewl2/build_tools/EWL_C/include/pa"`

add the `build_tools` subfolder in the 'Includes' of the C compiler and the 'General' of the Assembler 

3. May need to provide absolute `"${ProjDirPath}/include"` path instead relative for `../include/` 
