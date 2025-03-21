fun main() {
  // задание 1
    val stroke0 = readLine()
    if(stroke!=null){
            val intOfStroke: Int = stroke.toInt() 
            if (intOfStroke in 65..90) {
                when (intOfStroke) {
                    76 -> print("Это согласная буква")
                    77 -> print("Это согласная буква")
                    68 -> print("Это согласная буква")
                    75 -> print("Это согласная буква")
                    else -> {
                        print("Возможно, это гласные буквы")
                    }
                }
            }
    			else {
                	print("Неизвестно")
            }
    }
    else{
        print("ошибка")
    }
    // задание 2
    val stroke1 = "popoi"
    val stroke2 = "upeer"
    val result = stroke1 + stroke2 
    println("объединенная строки $result") 



    //задние 3
    var stroke3 = "qwe"
    var res = CharArray(stroke.length) 

    for (i in 0 until stroke.length) {
        res[i] = stroke[stroke.length - 1 - i]
    }

    stroke = res.joinToString("")
    print(stroke)
        
}
