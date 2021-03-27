//
// TYBLEMeshManager.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmart_TYBLEMeshManager
#define TuyaSmart_TYBLEMeshManager

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "TYBleMeshDeviceModel.h"
#import "TYBLEMeshCommand.h"

#define kInitMeshName @"out_of_mesh"

NS_ASSUME_NONNULL_BEGIN

@class TYBLEMeshManager;

/// The bluetooth mesh for tuya when ble mesh manger do some action and received some messages.
@protocol TYBLEMeshManagerDelegate <NSObject>

@optional

/// Bluetooth status callback.
/// @param status Bluetooth status.
- (void)centralManagerStatusChange:(CBManagerState)status;

/// Activate child device callback.
/// @param name The device name.
/// @param deviceId The device ID.
/// @param error Error in activation. If an error occurs, ` name 'and' deviceid 'are empty.
- (void)activeDeviceSuccessWithName:(NSString *)name deviceId:(NSString *)deviceId error:(NSError *)error;

/// Activate sub device successfully callback.
/// @param manager TYBLEMeshManager.
/// @param device TYBleMeshDeviceModel.
/// @param devId The device ID.
/// @param error Error in activation. If an error occurs, ` name 'and' deviceid 'are empty.
- (void)bleMeshManager:(TYBLEMeshManager *)manager didActiveSubDevice:(TYBleMeshDeviceModel *)device devId:(NSString *)devId error:(NSError *)error;

/// Activate gateway device callback.
/// @param name The device name.
/// @param address The device address.
/// @param mac The gateway mac.
/// @param error Error.
- (void)activeWifiDeviceWithName:(NSString *)name address:(NSInteger)address mac:(NSInteger)mac error:(NSError *)error;

/// Activate device failure callback.
/// @param manager TYBLEMeshManager.
/// @param device The device.
/// @param error Error.
- (void)bleMeshManager:(TYBLEMeshManager *)manager didFailToActiveDevice:(TYBleMeshDeviceModel *)device error:(NSError *)error;

/// Activate completion callback.
- (void)didFinishToActiveDevList;

/// Disconnect device callback.
- (void)notifyCentralManagerDidDisconnectPeripheral;

/// Version number callback.
/// @param version Version.
- (void)notifyFirmwareWithVersion:(NSString *)version;

/// Login success notification, upgrade required.
/// @param address Current access device address.
- (void)notifyLoginSuccessWithAddress:(uint32_t)address;

/// Group operation callbacks, such as group delete device and new device, will be informed which device is through this callback.
/// @param address The device address.
/// @param error Error during operation.
- (void)deviceAddGroupAddress:(uint32_t)address error:(NSError *)error;

/// Equipment scanned to the distribution network.
/// @param manager TYBLEMeshManager.
/// @param device TYBleMeshDeviceModel.
- (void)bleMeshManager:(TYBLEMeshManager *)manager didScanedDevice:(TYBleMeshDeviceModel *)device;

- (void)notifyQueryGroupAddress:(uint32_t)localId nodeId:(uint32_t)nodeId;

/// Mesh callback for successful connection, subsequent local communication can be done directly
- (void)didConnectMeshNodeAndLoginMesh;

@end

/// @brief ( Tuya ) Bluetooth mesh manager, contains common sig mesh management classes, such as creating groups, issuing control commands, removing devices, etc.
///
/// We provide a particularly large number of extension interfaces that can be used for various methods and scenarios.
///
@interface TYBLEMeshManager : NSObject

/// shared instance
+ (instancetype)sharedInstance;

/// the system bluetooth status.
@property (nonatomic, assign) BOOL isPoweredOn;

/// the mesh connect status.
@property (nonatomic, assign) BOOL isLogin;

/// is a wifi device when activator execute.
@property (nonatomic, assign) BOOL isWifiDevice;

/// if a wifi device, the wifi device's node address.
@property (nonatomic, assign) uint32_t wifiAddress;

/// the device's node address when device ota.
@property (nonatomic, assign) uint32_t otaAddress;

/// the ssid for activator.
@property (nonatomic, strong) NSString *ssid;

/// the password for activator.
@property (nonatomic, strong) NSString *password;

/// the token for activator.
@property (nonatomic, strong) NSString *token;

/// the device authkey when active.
@property (nonatomic, strong) NSString *authKey;

/// the mesh node uuid.
@property (nonatomic, strong) NSString *uuid;

/// the mesh node product.
@property (nonatomic, strong) NSString *productId;

/// the mesh device version.
@property (nonatomic, strong) NSString *version;

/// New Wi-Fi address.
@property (nonatomic, assign) uint32_t wifiMac;

/// the delegate for ble mesh manager.
@property (nonatomic, weak) id<TYBLEMeshManagerDelegate> delegate;

/// Mesh entrance.
/// If the operation is a distribution network, fill in the default mesh name and password. At this time, it will only pass through the
/// `-(void) blemeshmanager: (tyblemeshmanager *) manager didscaneddevice: (tyblemeshdevicemodel *) device; ` returns the scan result.
/// @param name The mesh name.
/// @param pwd The mesh passward.
/// @param active Is it activated for distribution network.
/// @param wifiAddress Wifi address, Gateway distribution network needs, the rest will be transmitted to 0.
/// @param otaAddress OTA device address, required for OTA upgrade, and 0 for the rest.
- (void)startScanWithName:(NSString *)name
                      pwd:(NSString *)pwd
                   active:(BOOL)active
              wifiAddress:(uint32_t)wifiAddress
               otaAddress:(uint32_t)otaAddress;

/// Activate device.
/// @param includeGateway Whether to activate the gateway. If it is' yes', the gateway device that has been scanned into the device will be activated, and the remaining sub devices will not be activated.
/// On the contrary, activate all the scanned ordinary mesh sub devices, and do not activate the gateway.
- (void)activeMeshDeviceIncludeGateway:(BOOL)includeGateway;

/// Activate a specific device.
/// @param deviceModel The device model.
- (void)activeMeshDevice:(TYBleMeshDeviceModel *)deviceModel;

/// Stop activating device.
- (void)stopActiveDevice;

- (void)getLightAllStatus;
- (BOOL)isConnected;
- (void)stopScan;
- (void)clearScanData;

/// Send command.
/// @param command Command.
- (void)sendCommand:(TYBLEMeshCommand *)command;

/// Write Wi Fi information to the gateway. This method will be called automatically after activation with SDK.
/// @param ssid Router hotspot name.
/// @param pwd Router hotspot password.
/// @param token Distribution network token.
- (void)startConfigWiFiWithSsid:(NSString *)ssid
                            pwd:(NSString *)pwd
                          token:(NSString *)token;

/// Read firmware version number.
- (void)readFirmwareFeature;

/// Send upgrade package.
/// @param address The device address.
/// @param version Version.
/// @param otaData Ota data.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)sendOTAPackWithAddress:(NSInteger)address
                       version:(NSString *)version
                       otaData:(NSData *)otaData
                       success:(TYSuccessHandler)success
                       failure:(TYFailureHandler)failure;

/// To get the mesh product name, you need to associate the product with the app in advance, otherwise it will return to null.
/// @param productId The product id.
/// @param completion Complete callback.
- (void)getProductNameByProductId:(NSString *)productId
                       completion:(void(^)(NSString *))completion;

@end

@interface TYBLEMeshManager (Command)

/// Set the mode of the lamp (exclusive for lighting class).
/// @param address Address.
/// @param type Device size class.
/// @param isGroup Is it a group.
/// @param param Param.
- (void)setLightModelWithAddress:(uint32_t)address
                            type:(NSString *)type
                         isGroup:(BOOL)isGroup
                           param:(NSArray<NSString *> *)param;

/// Read the scene mode of the lamp (lighting class exclusive).
/// @param address The device address.
/// @param type Device size class.
- (void)getLightSceneModelWithAddress:(uint32_t)address
                                 type:(NSString *)type;

/// Get low power (gate) state.
/// @param deviceAddress The device address.
/// @param dps Dps.
/// @param type Type.
- (void)getSensorStateWithAddress:(uint32_t)deviceAddress
                              dps:(NSArray *)dps
                             type:(NSString *)type;

/// Add device to group.
/// @param deviceAddress The device address.
/// @param type Type.
/// @param groupAddress The group address.
- (void)addDeviceAddress:(uint32_t)deviceAddress
                    type:(NSString *)type
            groupAddress:(uint32_t)groupAddress;

/// Remove device from group.
/// @param deviceAddress The device address.
/// @param type Type.
/// @param groupAddress The group Address.
- (void)deleteDeviceAddress:(uint32_t)deviceAddress
                       type:(NSString *)type
               groupAddress:(uint32_t)groupAddress;

/// Delete a group from mesh.
/// @param groupAddress The group address.
/// @param type The group type.
- (void)deleteGroupAddress:(uint32_t)groupAddress
                      type:(NSString *)type;

/// Get the group address corresponding to the device.
/// @param deviceAddress The device address.
/// @param type Type.
- (void)getGroupAddressWithDeviceAddress:(uint32_t)deviceAddress
                                    type:(NSString *)type;

/// Get all the devices in the group.
/// @param groupAddress The group address.
/// @param type The group type.
- (void)getDevicesAddressWithGroupAddress:(uint32_t)groupAddress
                                     type:(NSString *)type;

/// Remove a device from mesh network.
/// @param address The device address.
/// @param type Type.
- (void)kickoutLightWithAddress:(uint32_t)address
                           type:(NSString *)type;

/// Get the status of a device, such as the RGB of a light...
/// @param address The device address.
/// @param type Type.
- (void)getDeviceStatusAllWithAddress:(uint32_t)address
                                 type:(NSString *)type;

/// Get countdown data of equipment (exclusive for electricians).
/// @param address The device address.
/// @param type Type.
- (void)getDeviceCountdownWithAddress:(uint32_t)address
                                 type:(NSString *)type;

@end

@interface TYBLEMeshManager (Raw)

/** The commands here are issued and controlled under the gateway connection. */

/// Delete a group from mesh.
/// @param groupAddress The group address.
/// @param type Type.
- (NSString *)rawDataDeleteGroupAddress:(uint32_t)groupAddress
                                   type:(NSString *)type;

/// Remove a device from a group.
/// @param deviceAddress The device address.
/// @param groupAddress The group address.
/// @param type Type.
- (NSString *)rawDataDeleteDeviceAddress:(uint32_t)deviceAddress
                            groupAddress:(uint32_t)groupAddress
                                    type:(NSString *)type;

/// Add a device to a group.
/// @param deviceAddress The device address.
/// @param groupAddress The group address.
/// @param type Type.
- (NSString *)rawDataAddDeviceAddress:(uint32_t)deviceAddress
                         groupAddress:(uint32_t)groupAddress
                                 type:(NSString *)type;

/// Get all devices under the specified group.
/// @param groupAddress The group address.
/// @param type Type.
- (NSString *)rawDataGetDevicesAddressWithGroupAddress:(uint32_t)groupAddress
                                                  type:(NSString *)type;

/// Kick a device out of mesh.
/// @param address The device address.
/// @param type Type.
- (NSString *)rawDataKickoutLightWithAddress:(uint32_t)address
                                        type:(NSString *)type;

/// Get the corresponding device status.
/// @param address The device address.
/// @param type Type.
- (NSString *)rawDataGetStatusAllWithAddress:(uint32_t)address
                                        type:(NSString *)type;

/// Get device countdown (exclusive for electricians).
/// @param address Teh devce address.
/// @param type Type.
- (NSString *)rawDataCountDownWithAddress:(uint32_t)address
                                     type:(NSString *)type;

@end

#endif

NS_ASSUME_NONNULL_END
