import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "Grpc"
    Depends { name: "Qt"; submodules: ["core","protobuf","network"]}

    architectures: ["x86_64"]
    targetPlatform: "windows"
    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: []
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt6Grpc"
    libNameForLinkerRelease: "Qt6Grpc"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6Grpc.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_GRPC_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtGrpc"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["grpc"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
