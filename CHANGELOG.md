# Estimote Proximity SDK Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/en/1.0.0/)
and this project adheres to [Semantic Versioning](http://semver.org/spec/v2.0.0.html).

## [1.3.0] - 2019-03-27

### Changed:
- Updated to Swift 5. If you're still on an earlier version of Swift, use 1.2.0.

## [1.2.0] - 2018-09-19

### Added:
- Support for Swift 4.2 and the new build system in Xcode 10.

### Changed:
- The SDK drops support for the arm7vs architecture.

## [1.2.1] - 2018-12-27

### Changed:
- Dependecy on [Estimote Bluetooth Scanning library](https://github.com/Estimote/iOS-Bluetooth-Scanning) to match its version `1.0.0-alpha`.

## [1.2.0] - 2018-09-19

### Added:
- Support for Swift 4.2 and the new build system in Xcode 10.

### Changed:
- The SDK drops support for the arm7vs architecture.

## [1.1.0] - 2018-08-20

### Added:
- `ProximityObserverConfiguration` now supports enabling/disabling reporting telemetry to Cloud, requesting CL authorization, and setting logs level.

## [1.0.0] - 2018-07-26

### Added:
- Enforcing Core Location Services permissions — in order to report enter/exit events, your apps need either `WhenInUse` (to work when the app is active) or `Always` (to work in background as well) permission.
- Proximity SDK now supports telemetry reporting to Estimote Cloud.

### Changed:
- Errors related to the SDK initialization, zone observation, and Location Services are more descriptive.
- `EPXProximityZoneContext` is not a protocol anymore, but a class (so you can use it nicely within your Swift apps).
- Swift classes have no `EPX` prefixes.
- Parameters and naming in `ProximityZone`'s `init` and event callbacks now follows a clearer convention, and is consistent with the Android version.

### Removed:
- `EPXDeviceAttachment` class.
- DeskObservers sample apps - from now on please use [app templates](https://cloud.estimote.com/#/apps/add) as a reference instead.

## [0.14.0] - 2018-06-19
>**Warning: Breaking changes - new, tag based API!**

### Added:
- Protocol `EPXProximityZoneContext`, a bundle of device identifier, and assigned to it tag and list of attachments.

### Changed:
- Initializing `EPXProximityZone` with `tag` and `range` (instead of previous attachment's key-value pair and range).
- `EPXProximityZone`'s callbacks return `EPXProximityZoneContext`-compliant objects (instead of previous `EPXProximityDeviceAttachment`).

### Removed:
- previous attachment-based API is removed (not deprecated!), please read carefully [this](https://github.com/Estimote/iOS-Proximity-SDK/blob/master/README.md).

## [0.13.1] - 2018-05-15
### Fixed
- Fixed `EPXTimerAnalyticsHeartbeatGenerator` crash ([issue](https://github.com/Estimote/iOS-Proximity-SDK/issues/12)).

## [0.13.0] - 2018-05-09

### Added
- Estimote Monitoring is supporting pagination. Previously you could fetch only up to 100 attachments.
- Local persistance for cloud attachments. Now the `EPXProximityObserver` will fetch data from the cloud on every `startObserving()` if the network is available. If not, it will use the locally persisted data. This way you can start scan without the internet access, provided that you have launched it at least once when network was available.

## [0.12.0] - 2018-04-11

### Fixed
- Fixed a bug with ABI (binary-level) changes in Swift 4.1 mentioned in [bug report](https://github.com/Estimote/iOS-Proximity-SDK/issues/7).


## [0.11.3] - 2018-03-22

### Changed
- Private headers are no longer processed when building framework. This has a potential to resolve SourceKit issues in Swift example mentioned in [bug report](https://github.com/Estimote/iOS-Proximity-SDK/issues/5).


## [0.11.2] - 2018-03-14

### Changed
- Changed rules for post processing private headers when building framework to partially resolve SourceKit issues in Swift example mentioned in [bug report](https://github.com/Estimote/iOS-Proximity-SDK/issues/5).


## [0.11.1] - 2018-03-06

### Fixed
- Fixed a bug where Proximity Zone's `onEnterAction`, `onExitAction` & `onChangeAction` wouldn't be invoked when the app was in the background.


## [0.11.0] - 2018-03-01

### Added
- Estimote Secure Monitoring support.

### Changed
- Lack attachments assigned to devices does not stop observing proximity zones.

### Removed
- Case `NoAttachmentsMatchingZone` of enum`EPXProximityObserverError`.

## [0.10.0] - 2018-01-23

### Changed
- Estimote Proximity SDK now uses attachments configured in Estimote Cloud. No more encoding JSONs in tags!
- Renamed `EPXProximityDeviceAttachment` to `EPXDeviceAttachment`.
- `EPXProximityZone`'s `attachmentValue` is now `nonnull`.

### Added
- Added `EPXProximityObserverConfiguration` - it allows configuring Proximity Observer. At the moment, it only contains log level, but will be extended in the future.

### Removed
- Removed deprecated `EPXDeviceAttachment`'s `json` property. From now on, use `payload`.


## [0.9.0] - 2018-01-12

### Added
- Added `.payload` property of `EPXProximityDeviceAttachment` which represents content of attachment defined in Estimote Cloud. This property replaces `.json`.

### Deprecated
- Deprecated `.json` property of `EPXProximityDeviceAttachment` - use `payload` instead.

### Fixed
- Fixed headerdoc `initWithDesiredMeanTriggerDistance` to explain nullability.


## [0.8.0] - 2018-01-04

### Fixed
- Fixed  `Cannot remove an observer <CBPeripheral>` crash on iOS 11. It could occur when multiple Estimote's SDKs were used in one app project.

### Changed
- Added dependency on [Estimote Bluetooth Scanning library](https://github.com/Estimote/iOS-Bluetooth-Scanning).


## [0.7.1] - 2017-12-21

### Fixed
- Fixed an issue where Estimote Cloud Analytics batches sending would fail (getting 400 error).


## [0.7.0] - 2017-12-20

### Added
- `EPXProximityObserver`, `EPXProximityZone`, `EPXProximityRange`, `EPXProximityDeviceAttachment` classes for beacon proximity detection & beacon identification.
- Estimote Monitoring algorithm with motion detection for reliable beacon proximity detection experience.
- Built-in visit analytics sending. The collected data can be seen in [Estimote Cloud](https://cloud.estimote.com/#/analytics).
