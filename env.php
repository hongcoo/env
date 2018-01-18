<?php

Class Env{
    /**
     * 当前php.ini中配置的env.name的值
     */
    const ENVIRON = 'product';

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
}
