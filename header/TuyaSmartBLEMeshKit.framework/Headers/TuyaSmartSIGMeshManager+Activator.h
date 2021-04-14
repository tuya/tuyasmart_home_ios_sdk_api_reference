//
// TuyaSmartSIGMeshManager+Activator.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartBLEMeshKit/TuyaSmartBLEMeshKit.h>

/// @brief SIG mesh activator Category for (SIG) bluetooth mesh manager.=====The Bluetooth mesh activator category for the Bluetooth mesh manager.
///
/// Mainly contains the function entry for the device to start scanning and activating.======This API provides multiple functions such as device scanning and activation.
@interface TuyaSmartSIGMeshManager (Activator)

/// Starts to scan devices.
/// @param scanType At present, the scanning type is divided into non distribution network and distributed network. The scanned result of distribution network will automatically enter the network.======The devices to be scanned are classified into the paired devices and the devices that are not paired. The devices that are not paired are added to the network after they are scanned.
/// @param meshModel The mesh model.
- (void)startScanWithScanType:(TuyaSmartSIGScanType)scanType meshModel:(TuyaSmartBleMeshModel *)meshModel;

/// Start to activate devices.
/// @param devList The list of devices to be activated.
/// @param meshModel The mesh model information.
- (void)startActive:(NSArray<TuyaSmartSIGMeshDiscoverDeviceInfo *> *)devList meshModel:(TuyaSmartBleMeshModel *)meshModel;

/// Stops device activation.
- (void)stopActiveDevice;

/// Stops device scanning.
- (void)stopSerachDevice;

/// Returns the node ID for the current connection.
- (NSString *)currentConnectNodeId;

@end

