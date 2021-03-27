//
// TuyaSmartSIGMeshManager.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// The type of sig mesh manager for inactive and active.
typedef NS_ENUM(NSUInteger, TuyaSmartSIGScanType) {
    /// Scan equipment without distribution network
    ScanForUnprovision,
    /// Scan the equipment with distribution network.
    ScanForProxyed,
};

@class TuyaSmartSIGMeshManager;

@class TuyaSmartSIGMeshDiscoverDeviceInfo;

/// The sig mesh manager delegate, when sig mesh manager handle some message, will call it.
@protocol TuyaSmartSIGMeshManagerDelegate <NSObject>

@optional;

/// Activate sub device successfully callback.
/// @param manager TuyaSmartSIGMeshManager.
/// @param device TuyaSmartSIGMeshDiscoverDeviceInfo.
/// @param devId The device ID.
/// @param error Error in activation. If an error occurs, ` name 'and' deviceid 'are empty.
- (void)sigMeshManager:(TuyaSmartSIGMeshManager *)manager didActiveSubDevice:(TuyaSmartSIGMeshDiscoverDeviceInfo *)device devId:(NSString *)devId error:(NSError *)error;

/// Activate device failure callback.
/// @param manager TuyaSmartSIGMeshManager.
/// @param device TuyaSmartSIGMeshDiscoverDeviceInfo.
/// @param error Error in activation.
- (void)sigMeshManager:(TuyaSmartSIGMeshManager *)manager didFailToActiveDevice:(TuyaSmartSIGMeshDiscoverDeviceInfo *)device error:(NSError *)error;

/// Activate completion callback.
- (void)didFinishToActiveDevList;

/// Disconnect device callback.
- (void)notifyCentralManagerDidDisconnectPeripheral;

/// Equipment scanned to the distribution network.
/// @param manager TuyaSmartSIGMeshManager.
/// @param device TuyaSmartSIGMeshDiscoverDeviceInfo.
- (void)sigMeshManager:(TuyaSmartSIGMeshManager *)manager didScanedDevice:(TuyaSmartSIGMeshDiscoverDeviceInfo *)device;

/// Group operation completed.
/// @param manager TuyaSmartSIGMeshManager.
/// @param groupAddress Group mesh address, hex.
/// @param nodeId Device mesh node address, hexadecimal.
/// @param error Error.
- (void)sigMeshManager:(TuyaSmartSIGMeshManager *)manager didHandleGroupWithGroupAddress:(NSString *)groupAddress deviceNodeId:(NSString *)nodeId error:(NSError *)error;

/// Find device group list.
/// @param manager TuyaSmartSIGMeshManager.
/// @param groupList Group address list.
/// @param deviceModel The device model.
/// @param error Error.
- (void)sigMeshManager:(TuyaSmartSIGMeshManager *)manager
        queryGroupList:(NSArray<NSString *> *)groupList
           deviceModel:(TuyaSmartDeviceModel *)deviceModel
                 error:(NSString * _Nullable)error;

/// Login success notification, upgrade required.
- (void)notifySIGLoginSuccess;

/// Mesh callback for successful connection, subsequent local communication can be done directly
- (void)didConnectMeshNodeAndLoginMesh;

- (void)sigMeshManager:(TuyaSmartSIGMeshManager *)manager queryDeviceModel:(TuyaSmartDeviceModel *)deviceModel groupAddress:(uint32_t)groupAddress;

//获取到opCode 和 payload回调
- (void)sigMeshManager:(TuyaSmartSIGMeshManager *)manager didReceivedCustomOpCodeData:(NSData *)opCode payload:(NSData *)payload;

//需要绑定的自定义model id list
- (NSArray<NSNumber *> *)listOfCustomModelIdWithSigMeshManager:(TuyaSmartSIGMeshManager *)manager;

@end


/// @brief SIG Bluetooth mesh manager, contains common sig mesh management classes, such as creating groups, issuing control commands, removing devices, etc.
///
/// We provide a particularly large number of extension interfaces that can be used for various methods and scenarios.
/// 
@interface TuyaSmartSIGMeshManager : NSObject

+ (instancetype)sharedInstance;

@property (nonatomic, assign, readonly) BOOL isLogin;

@property (nonatomic, strong) TuyaSmartBleMesh *sigMesh;

@property (nonatomic, weak) id<TuyaSmartSIGMeshManagerDelegate> delegate;

@property (nonatomic, copy) NSString *otaTargetNodeId; /// Node ID of the upgraded device.

@end

NS_ASSUME_NONNULL_END
