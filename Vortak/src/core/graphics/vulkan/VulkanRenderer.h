// #pragma once
//
// #include "core/graphics/BufferManager.h"
// #include "utils/Base.h"
// #include "core/graphics/vulkan/VulkanPipeline.h"
// #include "core/graphics/Renderer.h"
// #include "core/graphics/vulkan/VulkanUBOManager.h"
// #include "core/graphics/vulkan/VulkanDevice.h"
// #include "core/graphics/vulkan/VulkanSwapChain.h"
// #include "core/graphics/vulkan/VulkanDescriptorPool.h"
// #include "core/graphics/vulkan/VulkanTextureManager.h"
//
// #include "core/scene/Scene.h"
//
// namespace Vortak {
//     class ImGuiOverlay;
//
//     constexpr uint32_t e_MaxEntities = 100;
//
//     class VulkanRenderer : public Renderer {
//     public:
//         struct PushConstants {
//             glm::mat4 transform{1.f};
//             glm::mat4 normalMatrix{1.f};
//             glm::mat4 modelMatrix{1.0f};
//         };
//
//         explicit VulkanRenderer(const Builder& builder);
//
//         ~VulkanRenderer() override;
//
//         VulkanDevice* getPlatform() const { return mVulkanDevice; }
//
//         SwapChain* getSwapChain() const override { return mVulkanSwapChain; }
//
//
//         vk::RenderPass getRenderPass() const { return mRenderPass; }
//
//         bool beginFrame() override;
//
//         void render(Vortak::Camera* camera, Vortak::Scene* scene) override;
//
//         void endFrame() override;
//
//     private:
//         void initialize();
//
//         void bindScene();
//
//         void createRenderPass();
//
//         void createFrameBuffers();
//
//         void createDepthImageView();
//
//         void initializeDescriptors();
//
//         void createCommandPool();
//
//         void createCommandBuffers();
//
//         void createSemaphores();
//
//         void createFences();
//
//         void handleWindowResize();
//
//         void beginRecording(vk::CommandBuffer commandBuffer);
//
//         void endRecoding(vk::CommandBuffer commandBuffer);
//
//         void updateUniformBuffers();
//
//         void destroyRenderPass();
//
//         void destroyFrameBuffers();
//
//         void destroyDepthImageView();
//
//         Scene* mScene = nullptr;
//         VulkanDevice* mVulkanDevice = nullptr;
//         VulkanSwapChain* mVulkanSwapChain = nullptr;
//         VulkanSwapChain::SwapChainDetails mSwapChainDetails = {};
//
//         vk::Viewport mViewport;
//         vk::Rect2D mScissor;
//
//         vk::RenderPass mRenderPass = nullptr;
//
//         vk::Image mDepthImage;
//         vk::DeviceMemory mDepthImageMemory;
//         vk::ImageView mDepthImageView;
//
//         std::vector<vk::Framebuffer> mFrameBuffers;
//
//         Vortak::VulkanUBOManager* mVulkanUBOManager = nullptr;
//         Vortak::BufferManager* mBufferManager = nullptr;
//         Vortak::VulkanTextureManager* mVulkanTextureManager = nullptr;
//         Vortak::Window* mWindow = nullptr;
//
//         std::vector<vk::Semaphore> mImageAvailableSemaphores;
//         std::vector<vk::Semaphore> mRenderFinishedSemaphores;
//         std::vector<vk::Fence> mInFlightFences;
//
//         uint32_t mCurrentFrame = 0;
//
//         vk::CommandPool mCommandPool = nullptr;
//         std::vector<vk::CommandBuffer> mCommandBuffers;
//         vk::CommandBuffer mCurrentCommandBuffer = nullptr;
//
//         uint32_t mCurrentImageIndex = 0;
//
//         vk::Device mLogicalDevice = nullptr;
//         vk::PhysicalDevice mPhysicalDevice = nullptr;
//         PushConstants mPushConstants;
//
//         std::vector<std::shared_ptr<VulkanBuffer> > mUniformBuffers;
//         VulkanDescriptorPool* mDescriptorPool = nullptr;
//         std::unordered_map<uint32_t, vk::DescriptorSet> mUniformDescriptorSets;
//         std::unordered_map<uint32_t, vk::DescriptorSet> mMaterialDescriptorSets;
//
//         vk::DescriptorSetLayout mUboDescriptorSetLayout = nullptr;
//         vk::DescriptorSetLayout mMaterialDescriptorSetLayout = nullptr;
//         vk::PipelineLayout mPipelineLayout = nullptr;
//         vk::Pipeline* mBoundPipeline = nullptr;
//         std::unordered_map<PipelineDescription*, std::unique_ptr<VulkanPipeline>> mPipelines;
//         Vortak::Timer* mTimer = nullptr;
//     };
// }
