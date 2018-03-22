# Estimote Proximity SDK Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/en/1.0.0/)
and this project adheres to [Semantic Versioning](http://semver.org/spec/v2.0.0.html).


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
