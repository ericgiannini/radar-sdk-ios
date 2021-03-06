Pod::Spec.new do |s|
  s.name                  = 'RadarSDK'
  s.version               = '1.1.14'
  s.summary               = 'iOS SDK for Radar, the free location platform for mobile apps'
  s.homepage              = 'https://www.onradar.com'
  s.social_media_url      = 'https://twitter.com/radarlabs'
  s.author                = { 'Radar Labs, Inc.' => 'support@onradar.com' }
  s.platform              = :ios
  s.source                = { :git => 'https://github.com/radarlabs/radar-sdk-ios.git', :tag => s.version.to_s }
  s.source_files          = 'RadarSDK/RadarSDK.framework/Versions/A/Headers/*.h'
  s.vendored_frameworks   = 'RadarSDK/RadarSDK.framework'
  s.module_name           = 'RadarSDK'
  s.ios.deployment_target = '8.0'
  s.frameworks            = 'CoreLocation'
  s.requires_arc          = true
  s.license               = { :type => 'Copyright',
                              :text => 'Copyright (c) 2017 Radar Labs, Inc. All rights reserved.' }
end
