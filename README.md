# Splitting-Datasets
A C++ tool to split a dataset into the training and test set, and split the trainind dataset for K-fold cross validation<br>
It also record image file names in each subset and save them in a seperate text file
<h2>two modes</h2>
<p>
basic_split, cross_validation
<p>example command input(7 classes, 5-fold cross-validation):<br> 
--basic_split C:\Users\Admin\Desktop\dataset 7<br>
--cross_validation C:\Users\Admin\Desktop\dataset\training 5 7 
<p>
./dataset<br>
0<br>1<br>2<br>3<br>4<br>5<br>6<br>
training(generated in basic_split)<br>
test(generated in basic_split)<br>
<br>after cross_validation<br>
./dataset/traning<br>
cr1<br>cr2<br>cr3<br>cr4<br>cr5<br>





