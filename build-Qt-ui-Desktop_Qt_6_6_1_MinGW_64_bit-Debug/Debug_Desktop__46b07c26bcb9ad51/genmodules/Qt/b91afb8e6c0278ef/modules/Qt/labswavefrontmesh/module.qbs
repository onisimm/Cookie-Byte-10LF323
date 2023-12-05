import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "LabsWavefrontMesh"
    Depends { name: "Qt"; submodules: ["core-private","gui-private","quick-private"]}

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
    libNameForLinkerDebug: "Qt6LabsWavefrontMesh"
    libNameForLinkerRelease: "Qt6LabsWavefrontMesh"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6LabsWavefrontMesh.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_LABSWAVEFRONTMESH_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtLabsWavefrontMesh"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["labswavefrontmesh"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
