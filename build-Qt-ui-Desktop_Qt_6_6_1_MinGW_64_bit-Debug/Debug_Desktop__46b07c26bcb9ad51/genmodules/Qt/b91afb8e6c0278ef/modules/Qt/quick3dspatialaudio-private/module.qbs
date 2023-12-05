import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "Quick3DSpatialAudio"
    Depends { name: "Qt"; submodules: ["quick3d-private","spatialaudio"]}

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
    libNameForLinkerDebug: "Qt6Quick3DSpatialAudio"
    libNameForLinkerRelease: "Qt6Quick3DSpatialAudio"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6Quick3DSpatialAudio.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_QUICK3DSPATIALAUDIO_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtQuick3DSpatialAudio","C:/Qt/6.6.1/mingw_64/include/QtQuick3DSpatialAudio/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtQuick3DSpatialAudio/6.6.1/QtQuick3DSpatialAudio"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["quick3dspatialaudio-private"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
