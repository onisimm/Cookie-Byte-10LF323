import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "Bodymovin"
    Depends { name: "Qt"; submodules: ["core","gui","gui-private"]}

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
    libNameForLinkerDebug: "Qt6Bodymovin"
    libNameForLinkerRelease: "Qt6Bodymovin"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6Bodymovin.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_BODYMOVIN_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtBodymovin","C:/Qt/6.6.1/mingw_64/include/QtBodymovin/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtBodymovin/6.6.1/QtBodymovin"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["bodymovin-private"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
