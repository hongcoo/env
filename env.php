<?php

// php.ini 中 env.name的值，默认值为product, 支持product(线上)、gray(灰度)、dev(开发)、local(本地),也支持自定义值
define('ENV_ENVIRON', 'product');

Class Env{
    /**
     * isProduct
     * @description 判断是否为线上
     * @version 1.0.0
     * @return bool
     */
    public static function isProduct(){}

    /**
     * isGray
     * @description 判断是否为灰度
     * @version 1.0.0
     * @return bool
     */
    public static function isGray(){}

    /**
     * isDev
     * @description 判断是否为开发
     * @version 1.0.0
     * @return bool
     */
    public static function isDev(){}

    /**
     * isLocal
     * @description 判断是否为本地
     * @version 1.0.0
     * @return bool
     */
    public static function isLocal(){}

    /**
     * getEnviron
     * @description 获取php.ini 中 env.name的值
     * @version 1.0.0
     * @return string
     */
    public static function getEnviron(){}
}
