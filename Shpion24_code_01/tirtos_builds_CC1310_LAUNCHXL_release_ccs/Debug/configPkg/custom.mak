## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,em3 linker.cmd package/cfg/release_pem3.oem3

# To simplify configuro usage in makefiles:
#     o create a generic linker command file name 
#     o set modification times of compiler.opt* files to be greater than
#       or equal to the generated config header
#
linker.cmd: package/cfg/release_pem3.xdl
	$(SED) 's"^\"\(package/cfg/release_pem3cfg.cmd\)\"$""\"E:/Shestakov/shpion24/Shpion24_code/Shpion24_code_01/tirtos_builds_CC1310_LAUNCHXL_release_ccs/Debug/configPkg/\1\""' package/cfg/release_pem3.xdl > $@
	-$(SETDATE) -r:max package/cfg/release_pem3.h compiler.opt compiler.opt.defs
