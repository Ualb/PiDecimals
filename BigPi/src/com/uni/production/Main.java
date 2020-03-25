package com.uni.production;

import java.math.BigDecimal;
import java.math.RoundingMode;

public class Main {

    public static void main(String[] args) {
        System.out.println(whallisProduct());
    }

    public static BigDecimal whallisProduct () {
        BigDecimal pi = new BigDecimal("1");
        BigDecimal counter = new BigDecimal("1");
        BigDecimal one = new BigDecimal("1");
        BigDecimal two = new BigDecimal("2");
        for (int i = 1; i < 100000; ++i) {

            pi = pi.multiply(two.multiply(counter))
                    .divide(two.multiply(counter).add(one), 3600, RoundingMode.HALF_UP)
                    .multiply(two.multiply(counter))
                    .divide(two.multiply(counter).subtract(one), 3600,RoundingMode.HALF_UP);
            counter = counter.add(one);
        }
        return pi.multiply(two);
    }
}
