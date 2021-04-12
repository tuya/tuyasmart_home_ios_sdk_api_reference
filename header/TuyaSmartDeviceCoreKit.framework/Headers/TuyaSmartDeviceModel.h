//
// TuyaSmartDeviceModel.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmart_TuyaSmartDeviceModel
#define TuyaSmart_TuyaSmartDeviceModel

#import "TuyaSmartSchemaModel.h"
#import "TuyaSmartDeviceModuleModel.h"
#import "TuyaSmartStandSchemaModel.h"
#import "TuyaSmartCommunication.h"

/// device types
typedef enum : NSUInteger {
    
    TuyaSmartDeviceModelTypeWifiDev,         /// Wi-Fi
    
    TuyaSmartDeviceModelTypeBle,             /// Single Point Bluetooth Device
    
    TuyaSmartDeviceModelTypeGprs,            /// Gprs
    
    TuyaSmartDeviceModelTypeNBIoT,           /// NB-IoT
    
    TuyaSmartDeviceModelTypeZigbeeGateway,   /// Zigbee Gateway
    
    TuyaSmartDeviceModelTypeZigbeeSubDev,    /// Zigbee subDevice
    
    TuyaSmartDeviceModelTypeMeshBleSubDev,   /// Mesh
    
    TuyaSmartDeviceModelTypeInfraredGateway, /// Infrared gateway
    
    TuyaSmartDeviceModelTypeInfraredSubDev,  /// Infrared subDevice
    
    TuyaSmartDeviceModelTypeWifiGateway,     /// Wi-Fi Gateway
    
    TuyaSmartDeviceModelTypeWifiSubDev,      /// Wi-Fi subDevice
    
    TuyaSmartDeviceModelTypeSIGMeshGateway,  /// SIG Mesh Gateway
    
    TuyaSmartDeviceModelTypeSIGMeshSubDev,   /// SIG Mesh subDevice

    TuyaSmartDeviceModelTypeBeacon,          /// Ble Beacon
    
    TuyaSmartDeviceModelTypeCat1,            /// Cat.1
} TuyaSmartDeviceModelType;


typedef NS_OPTIONS(NSUInteger, TuyaSmartDeviceOnlineType) {
    /// Offline
    TuyaSmartDeviceOnlineTypeOffline = 0,
    /// Wi-Fi online
    TuyaSmartDeviceOnlineTypeWifi = 1 << 0,
    /// Local online
    TuyaSmartDeviceOnlineTypeLan = 1 << 1,
    /// BLE online
    TuyaSmartDeviceOnlineTypeBLE = 1 << 2,
    /// Mesh BLE  online
    TuyaSmartDeviceOnlineTypeMeshBLE = 1 << 3
};

/// device information.
@interface TuyaSmartDeviceModel : NSObject

/// device Id
@property (nonatomic, strong) NSString     *devId;

/// name of device
@property (nonatomic, strong) NSString     *name;

/// link of device icon
@property (nonatomic, strong) NSString     *iconUrl;

/// ability of device
@property (nonatomic, assign) NSInteger    ability;

/// online of device
@property (nonatomic, assign) BOOL         isOnline;

/// cloud online of device
@property (nonatomic, assign) BOOL         isCloudOnline;

@property (nonatomic, assign) TuyaSmartDeviceOnlineType onlineType;

/// Communication Information. Gateway-sub-device, mesh-like device communication node information. Communication priority. Device connectivity.
@property (nonatomic, strong) TuyaSmartCommunication *communication;

/// whether the device is shared
@property (nonatomic, assign) BOOL         isShare;

@property (nonatomic, strong) NSString     *verSw;

/// data point of device
@property (nonatomic, strong) NSDictionary *dps;

/// data point execution time of device
@property (nonatomic, strong) NSDictionary *dpsTime;

/// product Id
@property (nonatomic, strong) NSString     *productId;

/// whether to support group
@property (nonatomic, assign) BOOL         supportGroup;

/// whether to support standard group
@property (nonatomic, assign) BOOL         supportSGroup;

/// type of gateway
@property (nonatomic, strong) NSString     *gwType;

/// protocol version of gateway
@property (nonatomic, assign) double       pv;

#if TARGET_OS_IOS

/// online status of LAN
@property (nonatomic, assign) BOOL         isLocalOnline;

/// gateway protocol version of LAN
@property (nonatomic, assign) double       lpv;

#endif

/// hardware baseline version
@property (nonatomic, assign) double       bv;

/// device latitude
@property (nonatomic, strong) NSString     *latitude;

/// device longitude
@property (nonatomic, strong) NSString     *longitude;

/// dp name
@property (nonatomic, strong) NSDictionary *dpName;

/// schema of device
@property (nonatomic, strong) NSString     *schema;
@property (nonatomic, strong) NSString     *schemaExt;
@property (nonatomic, strong) NSArray<TuyaSmartSchemaModel *> *schemaArray;

@property (nonatomic, strong) NSString     *runtimeEnv;

/// attribute
@property (nonatomic, assign) NSUInteger   attribute;

@property (nonatomic, strong) NSString     *localKey;

@property (nonatomic, strong) NSString     *uuid;

/// Media Access Control Address
@property (nonatomic, strong) NSString     *mac;

/// The network communication ability:0.wifi;1.cable;2.gprs;3.nb-iot; 10:bluetooth;11.blemesh;12.zigbee.
@property (nonatomic, assign) NSUInteger   capability;

@property (nonatomic, strong) NSString     *timezoneId;

@property (nonatomic, assign) long long    homeId;
@property (nonatomic, assign) long long    roomId;
@property (nonatomic, assign) long long    sharedTime;

/// order
@property (nonatomic, assign) NSInteger    displayOrder;
@property (nonatomic, assign) NSInteger    homeDisplayOrder;

@property (nonatomic, strong) NSString     *ip;

/// skills
@property (nonatomic, strong) NSDictionary *skills;

@property (nonatomic, strong) NSString     *cloudId;

#pragma mark - panel

@property (nonatomic, assign) BOOL         rnFind;
@property (nonatomic, assign) long long    i18nTime;
@property (nonatomic, strong) NSString     *ui;
@property (nonatomic, strong) NSString     *uiId;
@property (nonatomic, strong) NSString     *uiVersion;
@property (nonatomic, strong) NSString     *uiPhase;
@property (nonatomic, strong) NSString     *uiType;
@property (nonatomic, strong) NSString     *uiName;
@property (nonatomic, strong) NSDictionary *uiConfig;
@property (nonatomic, strong) NSDictionary *panelConfig;
@property (nonatomic, strong) NSString     *category;
@property (nonatomic, strong) NSString     *categoryCode;
@property (nonatomic, strong) NSArray      *quickOpDps;
@property (nonatomic, strong) NSArray      *displayDps;
@property (nonatomic, strong) NSArray      *faultDps;
@property (nonatomic, strong) NSDictionary *displayMsgs;
@property (nonatomic, strong) NSString     *switchDp;

@property (nonatomic, assign) BOOL         isNewFirmware;
@property (nonatomic, assign) NSTimeInterval activeTime;
@property (nonatomic, assign) long         errorCode;

@property (nonatomic, assign) TuyaSmartDeviceModelType deviceType;
@property (nonatomic, assign) BOOL         upgrading  __deprecated_msg("Use TuyaSmartDeviceOTAModel.otaUpgradeStatus instead");

@property (nonatomic, strong) NSDictionary *originJson;

@property (nonatomic, strong) TuyaSmartDeviceModuleModel *moduleMap;

@property (nonatomic, assign) NSUInteger    bizAttribute;

@property (nonatomic, strong) NSDictionary *meta;

- (BOOL)attributeIsSupport:(NSUInteger)i;
- (BOOL)capabilityIsSupport:(NSUInteger)i;
- (BOOL)devAttributeIsSupport:(NSUInteger)i;
- (BOOL)baseAttributeIsSupport:(NSUInteger)i;
- (BOOL)protocolAttributeIsSupport:(NSUInteger)i;

#pragma mark - subdevice
/// node Id
@property (nonatomic, strong) NSString     *nodeId;
@property (nonatomic, strong) NSString     *parentId;

/// mesh
@property (nonatomic, strong) NSString     *vendorInfo;
@property (nonatomic, assign) BOOL         isMeshBleOnline;
@property (nonatomic, strong) NSString     *pcc;

#pragma mark - discovery device
/// mark:  0: 1<<0 auto  3：1<<3 route
@property (nonatomic, assign) NSUInteger devAttribute;

/// sig mesh dev key
@property (nonatomic, strong) NSString     *devKey;

/// Whether to standardize.
@property (nonatomic, assign) BOOL standard;
@property (nonatomic, strong) TuyaSmartStandSchemaModel *standSchemaModel;

/// dpCodes
@property (nonatomic, strong, readonly) NSDictionary *dpCodes;

/// Last dp update time.
@property (nonatomic, assign) NSTimeInterval dpMaxTime;

/// Is it a virtual device.
@property (nonatomic, assign) BOOL isVirtualDevice;

// Use `baseAttributeIsSupport: index` to check feature
//
// index rules:
// 9: Tuya ble mesh device
// 10: Support network check
@property (nonatomic, assign) NSUInteger baseAttribute;

// Use `protocolAttributeIsSupport: index` to check feature
//
// index rules:
// 0: support sigmesh feature
// 1: support zigbee feature
// 2: support subpieces feature
@property (nonatomic, assign) NSInteger protocolAttribute;

/// Whether auto-upgrade is supported. Currently NB/Bluetooth mesh devices do not support auto-upgrade.
@property (nonatomic, assign) BOOL supportAuto;

/// Support OTA upgrade method, from left to right, decreasing priority:
/// 0: WIFI, 1: BLE, 2: SIGMESH, 3: NB
@property (nonatomic, strong) NSArray *otaUpgradeModes;

/// Bluetooth connection configuration.
@property (nonatomic, strong) NSDictionary *configMetas;

@end

#endif
