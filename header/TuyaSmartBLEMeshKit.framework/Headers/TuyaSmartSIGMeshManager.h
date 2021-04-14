//
// TuyaSmartSIGMeshManager.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// The type of sig mesh manager for inactive and active.=====The type of Bluetooth mesh manager for inactive and active devices.
typedef NS_ENUM(NSUInteger, TuyaSmartSIGScanType) {
    /// Scan equipment without distribution network=====Scans devices that are not paired.
    ScanForUnprovision,
    /// Scan the equipment with distribution network.=======Scans paired devices.
    ScanForProxyed,
};

@class TuyaSmartSIGMeshManager;

@class TuyaSmartSIGMeshDiscoverDeviceInfo;

/// The sig mesh manager delegate, when sig mesh manager handle some message, will call it.====The delegate of the Bluetooth mesh manager. The delegate is instantiated when the Bluetooth mesh manager processes messages.
@protocol TuyaSmartSIGMeshManagerDelegate <NSObject>

@optional;

/// Activate sub device successfully callback.=====The callback that is used when a sub-device is activated.
/// @param manager TuyaSmartSIGMeshManager.=====The value of TuyaSmartSIGMeshManager.
/// @param device TuyaSmartSIGMeshDiscoverDeviceInfo.======The value of TuyaSmartSIGMeshDiscoverDeviceInfo.
/// @param devId The device ID.
/// @param error Error in activation. If an error occurs, ` name 'and' deviceid 'are empty.======An error occurs while activating the sub-device. The values of `name' and 'deviceid' are empty in the response.
- (void)sigMeshManager:(TuyaSmartSIGMeshManager *)manager didActiveSubDevice:(TuyaSmartSIGMeshDiscoverDeviceInfo *)device devId:(NSString *)devId error:(NSError *)error;

/// Activate device failure callback.=====The callback that is used when a device failed to be activated.
/// @param manager The value of TuyaSmartSIGMeshManager.
/// @param device The value of TuyaSmartSIGMeshDiscoverDeviceInfo.
/// @param error An error occurs while activating the device.
- (void)sigMeshManager:(TuyaSmartSIGMeshManager *)manager didFailToActiveDevice:(TuyaSmartSIGMeshDiscoverDeviceInfo *)device error:(NSError *)error;

/// Activate completion callback.=====The callback that is used when the activation is completed.
- (void)didFinishToActiveDevList;

/// Disconnect device callback.=====The callback that is used when a device is disconnected.
- (void)notifyCentralManagerDidDisconnectPeripheral;

/// Equipment scanned to the distribution network.======Scans a device for pairing.
/// @param manager The value of TuyaSmartSIGMeshManager.
/// @param device The value of TuyaSmartSIGMeshDiscoverDeviceInf.
- (void)sigMeshManager:(TuyaSmartSIGMeshManager *)manager didScanedDevice:(TuyaSmartSIGMeshDiscoverDeviceInfo *)device;

/// Group operation completed.=====Completes the group operation.
/// @param manager The value of TuyaSmartSIGMeshManager.
/// @param groupAddress The group mesh address in the hexadecimal format.
/// @param nodeId Device mesh node address, hexadecimal.=====The device mesh node address in the hexadecimal format.
/// @param error The error.
- (void)sigMeshManager:(TuyaSmartSIGMeshManager *)manager didHandleGroupWithGroupAddress:(NSString *)groupAddress deviceNodeId:(NSString *)nodeId error:(NSError *)error;

/// Find device group list.======Queries the list of device groups.
/// @param manager The value of TuyaSmartSIGMeshManager..
/// @param groupList Group address list.======The list of group addresses.
/// @param deviceModel The device model.
/// @param error The error.
- (void)sigMeshManager:(TuyaSmartSIGMeshManager *)manager
        queryGroupList:(NSArray<NSString *> *)groupList
           deviceModel:(TuyaSmartDeviceModel *)deviceModel
                 error:(NSString * _Nullable)error;

/// Login success notification, upgrade required.======The notification of login success. This parameter is required for an update.
- (void)notifySIGLoginSuccess;

/// Mesh callback for successful connection, subsequent local communication can be done directly=====The callback that is used when a mesh network is connected. This enables subsequent local communication.
- (void)didConnectMeshNodeAndLoginMesh;

- (void)sigMeshManager:(TuyaSmartSIGMeshManager *)manager queryDeviceModel:(TuyaSmartDeviceModel *)deviceModel groupAddress:(uint32_t)groupAddress;

//获取到opCode 和 payload回调=====Returns the values of `opCode` and `payload`.
- (void)sigMeshManager:(TuyaSmartSIGMeshManager *)manager didReceivedCustomOpCodeData:(NSData *)opCode payload:(NSData *)payload;

//需要绑定的自定义model id list=====The list of model IDs to be managed by the Bluetooth mesh manager.
- (NSArray<NSNumber *> *)listOfCustomModelIdWithSigMeshManager:(TuyaSmartSIGMeshManager *)manager;

@end


/// @brief SIG Bluetooth mesh manager, contains common sig mesh management classes, such as creating groups, issuing control commands, removing devices, etc.=====The Bluetooth mesh manager supports common Bluetooth mesh management classes and enables multiple functions. For example, the classes can be called to create groups, send control commands, and remove devices.
///
/// We provide a particularly large number of extension interfaces that can be used for various methods and scenarios.====A large number of extension APIs are available to support various methods and scenarios.
/// 
@interface TuyaSmartSIGMeshManager : NSObject

+ (instancetype)sharedInstance;

@property (nonatomic, assign, readonly) BOOL isLogin;

@property (nonatomic, strong) TuyaSmartBleMesh *sigMesh;

@property (nonatomic, weak) id<TuyaSmartSIGMeshManagerDelegate> delegate;

@property (nonatomic, copy) NSString *otaTargetNodeId; /// The node ID of the updated device.

@end

NS_ASSUME_NONNULL_END
