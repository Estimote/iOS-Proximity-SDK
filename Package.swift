// swift-tools-version:5.7
import PackageDescription


let package = Package(
    name: "EstimoteProximitySDK",
    platforms: [
        .iOS(.v10)
    ],
    products: [
        .library(
            name: "EstimoteProximitySDK",
            targets: [
                "EstimoteProximitySDK"
            ]
        )
    ],
    targets: [
        .binaryTarget(
            name: "EstimoteProximitySDK",
            path: "./EstimoteProximitySDK/EstimoteProximitySDK.xcframework"
        )
    ]
)