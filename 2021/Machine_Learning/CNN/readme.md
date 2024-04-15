# Convolution Neural Network
> [!NOTE]  **Summary**
> There are total of **1** projects using regression model.
> Most used model : **RESNET18**

### Projects
| Name |Model|<div style="width: 150pt"> Last Update Date| Link |
|  :-: | :-:  |  :-:  | :-: |
| ImageClassification | ResNet18 | 2023/10/30  | [:open_file_folder:](ML2023-HW3-ImageClassification/) |

## What is CNN ?
Convolutional Neural Networks are a class of deep learning models specifically designed for tasks involving grid-like data, such as images and video. 

They have proven to be highly effective in tasks like image recognition, object detection, and image segmentation. 
<p align='center'>
<img  src='https://editor.analyticsvidhya.com/uploads/59954intro%20to%20CNN.JPG' width=400/>
</p>

## Sturcture of CNN

#### 1. Input Layer
The input is typically an image, represented as a grid of pixel values. Each pixel's intensity represents the color information.

#### 2. Convolutional Layer
Convolutional layers apply filters (`kernels`) to the input image. Kernels are small matrices that slide over the input, performing element-wise multiplication and summing the results to produce feature maps. **These filters help detect patterns, edges, and features in the input image.**

#### 3. Activation Function (ReLU)
Activation function, often ReLU introduces non-linearity to the model, allowing it to learn complex patterns.

#### 4. Pooling Layer / Flattening
Pooling layers **reduce the spatial dimensions** of the feature maps while retaining important information. Common pooling methods include **max pooling**  or **average pooling** .

After several convolutional and pooling layers, the output is flattened into a one-dimensional vector.

#### 5. Fully Connected (FC) Layers
The FC layers learn high-level features and relationships from the spatial features obtained by convolution and pooling.

#### 6. Output Layer
For image classification, the output represents the predicted class probabilities using an activation function like softmax. The class with the highest probability is considered the predicted class for the input image.

## Advantages of CNN
* **Effective Feature Learning**
    Learning hierarchical and spatial features from input data, making them highly effective for tasks like image recognition. 
    Pooling layers reduce the spatial dimensions of feature maps, retaining important information while decreasing computational complexity.
* **Translation Invariance**
    Convolutional layers, with shared weights, provide translation invariance. This means that the network can recognize patterns regardless of their position in the input space.
* **Parameter Sharing**
    The use of shared weights in convolutional layers reduces the number of parameters, making CNNs more efficient and easier to train compared to fully connected networks.
## Limitations of CNN
* **Fixed Input Size**
  Traditional CNN architectures are designed for fixed-size inputs. This can be a limitation when dealing with images or data of varying sizes. Resizing the input images or using architectures that handle variable input sizes can be solutions, but they may come with trade-offs.
* **Limited Understanding of Global Context**
    CNNs are effective at capturing local patterns and features but may struggle with understanding the global context of an entire scene. This limitation can be significant in applications where a holistic understanding of the input data is crucial, such as scene understanding in computer vision.
* **Dependency on Data Quantity and Quality**
    CNNs, especially deep architectures, require large amounts of labeled data for effective training. Obtaining a substantial and diverse dataset can be challenging, particularly in niche domains or areas with limited resources. The performance of CNNs is highly dependent on the quality and quantity of the training data available.