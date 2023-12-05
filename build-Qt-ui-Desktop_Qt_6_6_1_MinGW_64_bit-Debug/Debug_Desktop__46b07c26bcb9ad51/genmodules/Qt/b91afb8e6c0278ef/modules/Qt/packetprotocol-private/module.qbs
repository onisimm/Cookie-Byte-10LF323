import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "PacketProtocol"
    Depends { name: "Qt"; submodules: ["core-private"]}

    architectures: ["x86_64"]
    targetPlatform: "windows"
    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: ["mpr","userenv"]
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt6PacketProtocol"
    libNameForLinkerRelease: "Qt6PacketProtocol"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6PacketProtocol.a"
    pluginTypes: []
    moduleConfig: ["static"]
    cpp.defines: ["QT_PACKETPROTOCOL_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtPacketProtocol","C:/Qt/6.6.1/mingw_64/include/QtPacketProtocol/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtPacketProtocol/6.6.1/QtPacketProtocol"]
    cpp.libraryPaths: []
    isStaticLibrary: true
    Group {
        files: [Qt["packetprotocol-private"].libFilePath]
        filesAreTargets: true
        fileTags: ["staticlibrary"]
    }
}
