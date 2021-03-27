//
// TuyaSmartSIGMeshManager+Activator.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartBLEMeshKit/TuyaSmartBLEMeshKit.h>

/// @brief SIG mesh activator Category for (SIG) bluetooth mesh manager.
///
/// Mainly contains the function entry for the device to start scanning and activating.
@interface TuyaSmartSIGMeshManager (Activator)

/// Start scanning device.
/// @param scanType At present, the scanning type is divided into non distribution network and distributed network. The scanned result of distribution network will automatically enter the network.
/// @param meshModel The mesh model.
- (void)startScanWithScanType:(TuyaSmartSIGScanType)scanType meshModel:(TuyaSmartBleMeshModel *)meshModel;

/// Start activating device.
/// @param devList List of devices to be activated.
/// @param meshModel The mesh model information.
- (void)startActive:(NSArray<TuyaSmartSIGMeshDiscoverDeviceInfo *> *)devList meshModel:(TuyaSmartBleMeshModel *)meshModel;

/// Stop activating device.
- (void)stopActiveDevice;

/// Stop scanning device.
- (void)stopSerachDevice;

/// Gets the node ID of the current connection.
- (NSString *)currentConnectNodeId;

@end

