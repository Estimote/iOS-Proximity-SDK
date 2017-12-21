# Estimote Proximity SDK Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/en/1.0.0/)
and this project adheres to [Semantic Versioning](http://semver.org/spec/v2.0.0.html).

## [0.7.1] - 2017-12-21

### Fixed
- Issue where Estimote Cloud Analytics batches sending would fail (getting 400 error).


## [0.7.0] - 2017-12-20

### Added
- `EPXProximityObserver`, `EPXProximityZone`, `EPXProximityRange`, `EPXProximityDeviceAttachment` classes for beacon proximity detection & beacon identification.
- Estimote Monitoring algorithm with motion detection for reliable beacon proximity detection experience.
- Built-in visit analytics sending. The collected data can be seen in [Estimote Cloud](https://cloud.estimote.com/#/analytics).
