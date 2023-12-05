import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "Mqtt"
    Depends { name: "Qt"; submodules: ["core","network"]}

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
    libNameForLinkerDebug: "Qt6Mqtt"
    libNameForLinkerRelease: "Qt6Mqtt"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6Mqtt.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_MQTT_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtMqtt"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["mqtt"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
